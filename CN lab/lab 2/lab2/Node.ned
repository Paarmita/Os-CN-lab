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
        int Cid;
        @display("bgb=210,190");
    gates:
        input Nin;
        output Nout;
    submodules:
        L1: NetworkL {
            Nid = Cid;
        }
        L2: DataLinkL {
            Did = Cid;
            @display("p=142,127");
        }
    connections:
        L1.Nout --> L2.Din;
        L1.Nin <-- L2.Dout;
        L2.Gin <-- Nin;
        L2.Gout --> Nout;
}
