//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "data_layer.h"

Define_Module(Data_layer);

void Data_layer::initialize()
{
//    address = par("id_n");
        in1 = gate("dnIn");
        out1 = gate("dnOut");
        in2 = gate("dIn");
        out2 = gate("dOut");
        timeout = 1;
        timeoutEvent = new cMessage("timeoutEvent");
//        m_id = 1;
//        counter = 10;
//        input dnIn;
//        input dIn;
//        output dnOut;
//        output dOut;
}

void Data_layer::handleMessage(cMessage *msg)
{
    if(msg == timeoutEvent)
    {
        EV << "Timeout expired, resenting message and restarting timer\n";
//        dup_pkt2 = dup_pkt1 -> dup();
        //cancelEvent(timeoutEvent);
        scheduleAt(simTime()+timeout, timeoutEvent);
        EV << "Timeout Event DL  \n";
        send(dup_pkt1, out2);
        bubble("resending");
//        EV << "LOL 2 \n";

    }
    else
    {
        if( msg->getArrivalGate() == in1)
        {
            DL_PDU* d = new DL_PDU();
            N_PDU* m = check_and_cast<N_PDU*>(msg);
            d->encapsulate(m);
            d->setDP_type(0);
            dup_pkt1 = d -> dup();
            cancelEvent(timeoutEvent);
            scheduleAt(simTime()+timeout, timeoutEvent );
            send(d,out2);
        }


        else
        {
    //        N_PDU* d = new N_PDU();
            DL_PDU* ack = new DL_PDU();
            DL_PDU* m = check_and_cast<DL_PDU*>(msg);

            if(m->getDP_type() == 0)
            {
                if (uniform(0, 1) < 0.3)
                {
                    EV << "\"Losing\" message.\n";
                    bubble("message lost");  // making animation more informative...
                    delete msg;
                }

                else
                {
                    send(m->decapsulate(),out1);
                    ack->setDP_type(1);
            //        send(d,out1);
                    send(ack,out2);
                }
            }

            else
            {
                EV << "Timer cancelled.\n";
                cancelEvent(timeoutEvent);
                bubble("Deleted acknowledgment DL");
                delete(m);
            }
        }

    }
}

