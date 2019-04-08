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
    parameters :
        int address;
        
        gates:
            input gIn;
            output gOut;
            
            submodules:
                nl: Network_layer{nid=address;}
                dll: Datalink_layer{did=address;}
                
                connections:
                    nl.to_dll--> dll.from_nl;
                    nl.from_dll<-- dll.to_nl;
                    dll.from_nd<-- gIn;
                    dll.to_nd--> gOut;
                    
}
