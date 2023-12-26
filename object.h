#pragma once
class position {
    float x, y, theta;
};

class velocity {
    float vx, vy, w;
};

class weapon {
    float demage, radius;
    position pos;
    velocity V;
};

class gun :public weapon{
    float range;
};

class laser_gun :public gun {
    float line_width;
};

class machine_gun : public gun {
    float fire_speed;
};

class cannon : public gun {

};

class landmine : public weapon {

};

class bomb : public weapon {

};