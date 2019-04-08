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

network ForwardingNetwork
{
	
    @display("bgb=382,310");
    submodules:
        N[6]: Node {
            id = index;
            @display("is=vl");
        }


    connections allowunconnected:
        N[0].in[0] <-- {  delay = 150ms; } <-- N[1].out[0];
        N[0].in[1] <-- {  delay = 100ms; } <-- N[2].out[0];

        N[1].in[0] <-- {  delay = 150ms; } <-- N[0].out[0];
        N[1].in[1] <-- {  delay = 50ms; } <-- N[3].out[0];
        N[1].in[2] <-- {  delay = 100ms; } <-- N[4].out[0];

        N[2].in[0] <-- {  delay = 100ms; } <-- N[0].out[1];
        N[2].in[1] <-- {  delay = 200ms; } <-- N[3].out[1];
        N[2].in[2] <-- {  delay = 100ms; } <-- N[4].out[1];

        N[3].in[0] <-- {  delay = 50ms; } <-- N[1].out[1];
        N[3].in[1] <-- {  delay = 200ms; } <-- N[2].out[1];
        N[3].in[2] <-- {  delay = 100ms; } <-- N[5].out[0];

        N[4].in[0] <-- {  delay = 100ms; } <-- N[1].out[2];
        N[4].in[1] <-- {  delay = 100ms; } <-- N[2].out[2];
        N[4].in[2] <-- {  delay = 150ms; } <-- N[5].out[1];

        N[5].in[0] <-- {  delay = 100ms; } <-- N[3].out[2];
        N[5].in[1] <-- {  delay = 150ms; } <-- N[4].out[2];


}
