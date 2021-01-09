
#include <iostream>

namespace Snowy {

	__declspec(dllimport) void Print();

}

void main() {

	Snowy::Print();
}