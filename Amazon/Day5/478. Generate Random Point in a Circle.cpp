
class Solution {
    float pi= 3.141592;
public:
    double xx, yy, rad;
    double generate(){
        return ((double)rand()/(double)RAND_MAX);
    }
    Solution(double radius, double x_center, double y_center) {
        rad=radius;
        xx=x_center;
        yy=y_center;
    }
    vector<double> randPoint() {
        double xxx=rad*sqrt(generate());
        double angle=2*pi*generate();
        double new_x=xx+xxx*cos(angle);
        double new_y=yy+xxx*sin(angle);
        return {new_x,new_y};
    }
};