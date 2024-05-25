#include <iostream>
#include "FST.h"

int main() {
    FST automat;
    automat.citesteFST();
    automat.translate("abc");
    return 0;
}
