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

#include "networkL.h"

Define_Module(NetworkL);

void NetworkL::initialize()
{
    // TODO - Generated method body
    count=0;
    timeout=200;
    address = par("Nid");
    in = gate("Nin");
    out = gate("Nout");
    if(address == 1){
        cMessage* event = new cMessage();
        scheduleAt(0,event);
    }
}

void NetworkL::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg -> isSelfMessage()){
        count++;
        N_PDU *data = new N_PDU();
        data->setPId(count);
        data->setPType(0);
        data->setSrc(1);
        data->setDest(2);
        send(data,out);
        if(count<=10){
            cMessage* event = new cMessage();
            scheduleAt(simtime_t()+timeout,event);
        }
     }
    else{
        bubble("msg deleted");
        delete(msg);
    }
}
