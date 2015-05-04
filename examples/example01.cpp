#include <emc/io.h>
#include <emc/rate.h>

#include <iostream>

int main()
{
    // Create IO object, which will initialize the io layer
    emc::IO io;

    // Create Rate object, which will help using keeping the loop at a fixed frequency
    emc::Rate r(10);

    // Loop while we are properly connected
    while(io.ok())
    {
        // Send a reference to the base controller (vx, vy, vtheta)
//        io.sendBaseReference(0.1, 0, 0);

        emc::OdometryData odom;
        if (io.readOdometryData(odom))
            std::cout << odom.a << std::endl;

        // Sleep remaining time
        r.sleep();
    }

    return 0;
}
