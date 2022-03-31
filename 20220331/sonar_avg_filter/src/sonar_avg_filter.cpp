#include "ros/ros.h"
#include "sensor_msgs/Range.h"

using namespace ros;

sensor_msgs::Range range;
double r1,r2,r3,r4,r5;
void RangeCallback(const sensor_msgs::Range::ConstPtr& msg) {
	
	
	r1=r2=r3=r4=r5=msg->range;
	double Avg_range = r1+r2+r3+r4+r5 / 5.0;
	
	
	ROS_INFO("Range = [%6.3lf, %6.3lf, %6.3lf, %6.3lf, %6.3lf]", r1, r2, r3, r4, r5);
	
	ROS_INFO("Avg_range = [%6.3lf]", Avg_range);
}


int main(int argc, char **argv) {
	init(argc, argv, "sonar_avg_filter");
	NodeHandle n;
	Subscriber sub = n.subscribe("/range", 1000, RangeCallback);
	Publisher pub_avg_range = n.advertise<sensor_msgs::Range>("/range_avg", 1000);
	
	Rate loop_rate(10);
	
	while(ok()) 
	{
		pub_avg_range.publish(range);
		
		loop_rate.sleep();
		spinOnce();
	}
	
	return 0;
	
}
