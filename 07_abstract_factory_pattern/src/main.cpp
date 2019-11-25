#include <iostream>
#include <KdeWidgetFactory.h>
#include "Dummy.h"
#include "Demo.h"
int main() {

    auto dummy = Dummy{};
    std::cout << "dummy.integrate(2, 4) = " << dummy.integrate(2, 4) << std::endl;

    Demo demo(std::make_shared<KdeWidgetFactory>(2));
    demo.run("Button");

    return 0;
}