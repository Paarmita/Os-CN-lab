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

network LayerNetwork
{
    parameters:
        int src;
        int dest;
        int number;
        @display("bgb=288,199");
    submodules:
        Node1: Node {
            id = 1;
            @display("p=92.46667,56.45333");
        }
        Node2: Node {
            id = 2;
            @display("p=193.69333,103.17333");
        }

    connections:
        Node1.gIn <-- {  delay = 100ms; } <-- Node2.gOut;
        Node2.gIn <-- {  delay = 100ms; } <-- Node1.gOut;

}
