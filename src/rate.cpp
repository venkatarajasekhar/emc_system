#include "emc/rate.h"

#include <ros/rate.h>

namespace emc
{

Rate::Rate(double freq)
{
    ros::Time::init();
    rate_ = new ros::Rate(freq);
}

void Rate::sleep()
{
    rate_->sleep();
}

}
