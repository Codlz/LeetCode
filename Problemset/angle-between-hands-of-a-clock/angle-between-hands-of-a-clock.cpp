
// @Title: 时钟指针的夹角 (Angle Between Hands of a Clock)
// @Author: 554216885@qq.com
// @Date: 2020-10-14 13:11:43
// @Runtime: 0 ms
// @Memory: 6 MB

class Solution {
public:
    double angleClock(int hour, int minutes) {
        int angle_minute = 6, angle_hour = 30;
        hour = hour % 12;

        double angle1 = angle_minute * minutes;
        double angle2 = angle_hour * hour + 0.5 * minutes;
        double ans = abs(angle1 - angle2);
        if (ans > 180)
            ans = 360 - ans;
        
        return ans;
    }
};
