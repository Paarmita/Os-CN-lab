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

Define_Module(Node);

void Node::initialize()
{

    int temp;
    int find;
    nid = par("id");
    src = par("src");
    dest =par("dest");
    switch(nid)
    {
        case 0: m[1]=0;
                m[2]=1;
                m[3]=0;
                m[4]=1;
                m[5]=0;
                break;

        case 1: m[0]=0;
                m[2]=2;
                m[3]=1;
                m[4]=2;
                m[5]=1;
                break;

        case 2: m[0]=0;
                m[1]=2;
                m[3]=1;
                m[4]=2;
                m[5]=2;
                break;

        case 3: m[0]=0;
                m[1]=0;
                m[2]=1;
                m[4]=0;
                m[5]=2;
                break;

        case 4: m[0]=1;
                m[1]=0;
                m[2]=1;
                m[3]=0;
                m[5]=2;
                break;

        case 5: m[0]=0;
                m[1]=0;
                m[2]=1;
                m[3]=0;
                m[4]=1;
                break;
    }
    if(nid == src)
      {
          cMessage* event = new cMessage();
          scheduleAt(0,event);
      }
}

void Node::handleMessage(cMessage *msg)
{
    if(msg -> isSelfMessage())
          {
              N_PDU* data = new N_PDU();
              data->setM_dest(dest);
              data->setM_src(src);

              send(data, "out", m.at(dest));
          }
    else
    {

        N_PDU* pkt = check_and_cast<N_PDU*>(msg);
        if(pkt->getM_dest() == nid )
        {

            bubble("Delete");

            simtime_t eed = simTime() - msg->getCreationTime();
            EV << "Delay Of PAcket from Node " << src << " to " << dest <<" is :- " << eed*1000 << " ms";
            delete(msg);
        }

        else
        {
           int temp =  pkt->getM_dest();
           EV << "Routing Packet";
           send(pkt, "out", m.at(temp));

        }
    }


}
