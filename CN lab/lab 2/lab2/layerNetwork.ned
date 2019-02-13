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
    @display("bgb=189,227");
    submodules:
        N1: Node {
            Cid = 1;
        }
        N2: Node {
            Cid = 2;
            @display("p=152,156");
        }
    connections:
        N1.Nin <-- N2.Nout;
        N1.Nout --> N2.Nin;
}
