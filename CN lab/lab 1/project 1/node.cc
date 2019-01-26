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

#include "node.h"

#include<string.h>
Define_Module(Node);

void Node::initialize()
{
    // TODO - Generated method body
    address = par("id");
    in=gate("gIn");
    out=gate("gOut");
    if(address==1)
    {   cMessage* msg=new cMessage();
        scheduleAt(0,msg);
    }
}

void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    /*if(msg->isSelfMessage())
    {
        cMessage* M=new cMessage();
        send(M,out);
    }
    else
    {
        cMessage* R=new cMessage();
        send(R,out);
    }*/
    if(msg->isSelfMessage()){
       // N_PDU* p=check_and_cast<N_PDU*>(msg);
        N_PDU* pkt=new N_PDU();
        pkt->setId(1);
        cnt++;
        pkt->setType("data");
        pkt->setSrcaddress(1);
        pkt->setDeaddress(2);
        send(pkt,out);
    }
    else
    {
        if(cnt<10){
        N_PDU* p=check_and_cast<N_PDU*>(msg);
        if(strcmp(p->getType(),"data")==0){
           // p->setType("ack");
            N_PDU* pkt=new N_PDU();
                    pkt->setId(p->getId());
                   // cnt++;
                    pkt->setType("ack");
                    pkt->setSrcaddress(2);
                    pkt->setDeaddress(1);

            send(pkt,out);

        }
        else
        {
            cnt++;
            N_PDU* pkt=new N_PDU();
                               pkt->setId(p->getId()+1);
                              // cnt++;
                               pkt->setType("data");
                               pkt->setSrcaddress(1);
                               pkt->setDeaddress(2);

        //    p->setType("data");

            send(pkt,out);
        }
        }
     }
}
