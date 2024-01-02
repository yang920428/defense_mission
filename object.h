#pragma once

class position {
public:
    float x, y, theta;
};

class velocity {
public:
    float vx, vy, w;
};

class enemy {
public:
    int life;
    position pos;
    velocity V;
    bool enable = true;
};

class weapon {
public:
    float demage;
    float radius;
    position pos;
    velocity V;
    bool enable = false;
};

class gun :public weapon {
public:
    float range;
    int life;
};

class laser_gun : public gun {
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