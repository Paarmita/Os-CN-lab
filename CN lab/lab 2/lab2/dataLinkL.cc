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

#include "dataLinkL.h"

Define_Module(DataLinkL);

void DataLinkL::initialize()
{
    // TODO - Generated method body
    address = par("Did");
    d_in = gate("Din");
    d_out = gate("Dout");
    g_in = gate("Gin");
    g_out = gate("Gout");
//    cMessage* event = new cMessage();
//    scheduleAt(0,event);
}

void DataLinkL::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg -> getArrivalGate()==d_in){
        N_PDU *data = check_and_cast<N_PDU *>(msg);
        D_PDU *dldata = new D_PDU();
        dldata->encapsulate(data);
        dldata->setPType(0);
        dldata->setPId(data->getPId());
        send(dldata,g_out);
    }
    else{
        if(msg -> getArrivalGate()==g_in){
        D_PDU *data = check_and_cast<D_PDU *>(msg);
        if(data->getPType()==0){
            send(data->decapsulate(),d_out);
            D_PDU *ack=new D_PDU();
            ack->setPType(1);
            ack->setPId(data->getPId());
            bubble("ack dffdfdffffffffffffffffffff");
            send(ack,g_out);
        }
        else if(data->getPType()==1){
            bubble("ack recieved");
            delete(msg);
        }

    }
}

}
