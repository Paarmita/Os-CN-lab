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

#ifndef __LAB2_DATALINK_LAYER_H_
#define __LAB2_DATALINK_LAYER_H_

#include <omnetpp.h>
#include <D_PDU_m.h>
using namespace omnetpp;
/**
 * TODO - Generated class
 */
int counter;
class Datalink_layer : public cSimpleModule
{
  protected:
    int address;

        cGate*din_from_nl;
        cGate*dout_to_nl;
        cGate*din_from_nd;
        cGate*dout_to_nd;
        cMessage* event;

    virtual void initialize();
    //virtual void sendCopyOf(cMessage *msg);
    virtual void handleMessage(cMessage *msg);
};

#endif
