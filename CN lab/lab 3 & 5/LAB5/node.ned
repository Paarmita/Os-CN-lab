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

module Node
{
    parameters:
        int id;
    gates:
        input gIn;
        output gOut;

    submodules:
        NL: Network_layer {
            id_n = id;
        }
        DL: Data_layer {
            id_d = id;
            @display("p=69,79;is=s");
        }

    connections:
        DL.dIn <-- gIn;
        DL.dOut --> gOut;
        NL.nIn <-- DL.dnOut;
        NL.nOut --> DL.dnIn;

}
