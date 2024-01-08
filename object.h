#pragma once

class position {
public:
    int x, y, theta;
};

class velocity {
public:
    int vx, vy, w;
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
    int demage;
    int radius;
    position pos;
    velocity V;
    bool enable = false;
    int now_time;
};

class gun :public weapon {
public:
    int range;
    int life;
};

class laser_gun : public gun {
public:
    int line_range;
};

class machine_gun : public gun {
public:
    int fire_speed;
};

class cannon : public gun {

};

class landmine : public weapon {

};

class bomb : public weapon {

};