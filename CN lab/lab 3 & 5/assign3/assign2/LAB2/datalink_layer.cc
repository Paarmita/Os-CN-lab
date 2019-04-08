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

#include "datalink_layer.h"
#include<N_PDU_m.h>

Define_Module(Datalink_layer);





void Datalink_layer::initialize()
{
    address=par("did");
    counter=0;
    din_from_nl=gate("from_nl");
    dout_to_nl=gate("to_nl");
    din_from_nd=gate("from_nd");
    dout_to_nd=gate("to_nd");



}

//void Datalink_layer::sendCopyOf(cMessage *msg)
//{
        //cMessage *copy = (cMessage *)msg->dup();
       // send(copy, "dout_to_nd");
//}

void Datalink_layer::handleMessage(cMessage *msg)
{
    if(msg->getArrivalGate()==din_from_nl)
    {
        N_PDU* data=check_and_cast<N_PDU*>(msg);
        data->setPid(data->getPid());
        counter=data->getPid();
        D_PDU *p=new D_PDU();
        p->encapsulate(data);


        p->setType(0);
        send(p,dout_to_nd);

        event = new cMessage();

        scheduleAt(simTime()+200,event);


    }

    else if(msg->isSelfMessage())
    {
        //N_PDU *pr=new N_PDU();
        N_PDU* data=check_and_cast<N_PDU*>(msg);
        //data->setPid(counter);
        data->setType(0);
        D_PDU *p=new D_PDU();
        p->encapsulate(data);
        send(p,dout_to_nd);



    }
    else if(msg->getArrivalGate()==din_from_nd)
    {
        D_PDU* data=check_and_cast<D_PDU*>(msg);
            if(data->getType()==0)

        {
                if(uniform(0,1)<0.8)
                {

                    delete msg;
                }
                else
                {

                    send(data->decapsulate(),dout_to_nl);
                    //send(data,dout_to_nl);
                    data->setType(1);
                    send(data,dout_to_nd);



                }

        }
            else{cancelEvent(event);}

    }

}