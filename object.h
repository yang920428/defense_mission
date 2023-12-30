#pragma once

class position {
public:
    float x, y, theta;
};

class velocity {
public:
    float vx, vy, w;
};

class weapon {
public:
    float demage;
    int radius;
    position pos;
    velocity V;
};

class gun :public weapon{
public:
    float range;
};

class laser_gun : public gun{
public:
    float line_range;
};

class machine_gun : public gun {
public:
    float fire_speed;
};

class cannon : public gun {

};

class landmine : public weapon {

};

class bomb : public weapon {

};