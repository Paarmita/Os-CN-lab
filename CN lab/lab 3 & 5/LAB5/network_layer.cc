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

#include "network_layer.h"

Define_Module(Network_layer);

void Network_layer::initialize()
{
    address = par("id_n");
    in = gate("nIn");
    out = gate("nOut");
    m_id = 1;
    counter = 10;
 //  timeout = 1;
//    timeoutEvent = new cMessage("timeoutEvent");
    if(address == 1)
      {
          cMessage* event = new cMessage();
          scheduleAt(0,event);
      }
}

void Network_layer::handleMessage(cMessage *msg)
{
    if(msg -> isSelfMessage())
      {
          N_PDU* data = new N_PDU();
          data->setNP_type(0);
          data->setNP_id(counter);
          counter--;
          //cMessage* event = new cMessage();
          //scheduleAt(simTime() + 0.6, event);
          //scheduleAt(simTime()+timeout, timeoutEvent);
          send(data, out);

      }
    else
    {
        N_PDU* n_msg = check_and_cast<N_PDU*>(msg);

        if(n_msg->getNP_type() == 1)
        {
            if(counter >= 1)
            {
    //          To Do : Checking message id and ack id.
                N_PDU* data = new N_PDU();
                data->setNP_type(0);
                data->setNP_id(counter);
                counter--;
                bubble("Deleted Ack NL");

                send(data,out);
            }

        }

        else
        {
            if(counter >=1 )
            {
                bubble("Deleted Message NL");
                EV << "deleted \n" << "id  = " << n_msg->getNP_id();
                N_PDU* ack = new N_PDU();
                ack->setNP_type(1);
                ack->setNP_id(counter);
                send(ack,out);
                EV << "Network Layer Sends ACK ";

                delete(n_msg);
            }



        }
    }
}
