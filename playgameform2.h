#pragma once
#include <math.h>
#include <stdio.h>
#include <vector>
#include "object.h"
#include "gameoverform.h"
#include <math.h>
#include "nextform3.h"

namespace defense_mission {

    using namespace std;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// playgameform ���K�n
    /// </summary>
    public ref class playgameform2 : public System::Windows::Forms::Form
    {
    public:
        playgameform2(void)
        {
            InitializeComponent();
            //
            //TODO:  �b���[�J�غc�禡�{���X
            //
            //this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &playgameform2::playgameform_MouseClick);
        }
        // some variable
        int coin = 240;
        int system_counter = 0;
        enemy* enemy_normal = new enemy[5]();
        enemy* enemy_mid = new enemy[5]();
        weapon* lasergun_wea = new weapon[5]();
        weapon* cannon_wea = new weapon[5]();
        weapon* machinegun_wea = new weapon[5 * 10]();
        laser_gun* laser = new laser_gun[5]();
        machine_gun* machine = new machine_gun[5]();
        cannon* Cannon = new cannon[5]();
        landmine* Landmine = new landmine[5]();
        bomb* Bomb = new bomb[5]();
        bool* map = new bool[25]();
        bool* map_click_status = new bool[25]();
        float mouseX;
        float mouseY;
        float dt = 0.1;
        float dis;
        float dis2;
        float* dis_b = new float[5]();
        bool game = true;
        int killed;
        int initial_enemy_life = 150;
        int initial_enemy2_life = 1050;
        String^ musicfilepath = "d:\\program_set\\project_cpp\\defense_mission\\bgm2.wav";
        System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer(musicfilepath);

    private: System::Windows::Forms::Button^ button7;
    public:
    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::Button^ button9;
    private: System::Windows::Forms::Button^ button10;
    private: System::Windows::Forms::Button^ button11;
    private: System::Windows::Forms::Button^ button12;
    private: System::Windows::Forms::Button^ button13;
    private: System::Windows::Forms::Button^ button14;
    private: System::Windows::Forms::Button^ button15;
    private: System::Windows::Forms::Button^ button16;
    private: System::Windows::Forms::Button^ button17;
    private: System::Windows::Forms::Button^ button18;
    private: System::Windows::Forms::Button^ button19;
    private: System::Windows::Forms::Button^ button20;
    private: System::Windows::Forms::Button^ button21;
    private: System::Windows::Forms::Button^ button22;
    private: System::Windows::Forms::Button^ button23;
    private: System::Windows::Forms::Button^ button24;
    private: System::Windows::Forms::Button^ button25;
    private: System::Windows::Forms::Button^ button26;
    private: System::Windows::Forms::Button^ button27;
    private: System::Windows::Forms::Button^ button28;
    private: System::Windows::Forms::Button^ button29;
    private: System::Windows::Forms::Button^ button30;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::Label^ label11;
    private: System::Windows::Forms::Label^ label12;


    private: System::Windows::Forms::Button^ button31;

    protected:
        /// <summary>
        /// �M������ϥΤ����귽�C
        /// </summary>
        ~playgameform2()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::PictureBox^ pictureBox1;

    protected:

    private:

    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Timer^ timer1;
    private: System::ComponentModel::IContainer^ components;
    private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        // ploting on pictureBox1
        Graphics^ g = e->Graphics;
        Pen^ pen_yg = gcnew Pen(Color::YellowGreen, 5);
        g->DrawLine(pen_yg, 160, 0, 160, 394);
        g->DrawLine(pen_yg, 800, 0, 800, 394);
        // laser gun
        if (map[0] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_b2 = gcnew Pen(Color::Blue, 2);
            g->DrawEllipse(pen_b2, laser[0].pos.x - 10, laser[0].pos.y - 10, laser[0].radius, laser[0].radius);
            g->DrawLine(pen_b2, laser[0].pos.x, laser[0].pos.y, laser[0].pos.x + 20, laser[0].pos.y);
            if ((system_counter - this->lasergun_wea[0].now_time) % laser[0].shoot_v == 0) {
                Pen^ pen_y4 = gcnew Pen(Color::Yellow, 8);
                g->DrawLine(pen_y4, laser[0].pos.x + 10, laser[0].pos.y, laser[0].pos.x + 510, laser[0].pos.y);
                if (enemy_normal[0].pos.x <= laser[0].pos.x + 510) {
                    enemy_normal[0].life -= lasergun_wea[0].damage;
                    if (enemy_normal[0].life <= 0) {
                        enemy_normal[0].pos.x = 850;
                        enemy_normal[0].life = initial_enemy_life;
                        killed++;
                        coin += 20;
                    }
                }
                if (enemy_mid[0].pos.x <= laser[0].pos.x + 510) {
                    enemy_mid[0].life -= lasergun_wea[0].damage;
                    if (enemy_mid[0].life <= 0) {
                        enemy_mid[0].pos.x = 850;
                        enemy_mid[0].life = initial_enemy2_life;
                        killed++;
                        coin += 30;
                    }
                }
            }
        }
        if (map[1] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_b2 = gcnew Pen(Color::Blue, 2);
            g->DrawEllipse(pen_b2, laser[1].pos.x - 10, laser[1].pos.y - 10, laser[1].radius, laser[1].radius);
            g->DrawLine(pen_b2, laser[1].pos.x, laser[1].pos.y, laser[1].pos.x + 20, laser[1].pos.y);
            if ((system_counter - this->lasergun_wea[1].now_time) % laser[1].shoot_v == 0) {
                Pen^ pen_y4 = gcnew Pen(Color::Yellow, 8);
                g->DrawLine(pen_y4, laser[1].pos.x + 10, laser[1].pos.y, laser[1].pos.x + 510, laser[1].pos.y);
                if (enemy_normal[1].pos.x <= laser[1].pos.x + 510) {
                    enemy_normal[1].life -= lasergun_wea[1].damage;
                    if (enemy_normal[1].life <= 0) {
                        enemy_normal[1].pos.x = 850;
                        enemy_normal[1].life = initial_enemy_life;
                        killed++;
                        coin += 20;
                    }
                }
                if (enemy_mid[1].pos.x <= laser[1].pos.x + 510) {
                    enemy_mid[1].life -= lasergun_wea[1].damage;
                    if (enemy_mid[1].life <= 0) {
                        enemy_mid[1].pos.x = 850;
                        enemy_mid[1].life = initial_enemy2_life;
                        killed++;
                        coin += 30;
                    }
                }
            }
        }
        if (map[2] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_b2 = gcnew Pen(Color::Blue, 2);
            g->DrawEllipse(pen_b2, laser[2].pos.x - 10, laser[2].pos.y - 10, laser[2].radius, laser[2].radius);
            g->DrawLine(pen_b2, laser[2].pos.x, laser[2].pos.y, laser[2].pos.x + 20, laser[2].pos.y);
            if ((system_counter - this->lasergun_wea[2].now_time) % laser[2].shoot_v == 0) {
                Pen^ pen_y4 = gcnew Pen(Color::Yellow, 8);
                g->DrawLine(pen_y4, laser[2].pos.x + 10, laser[2].pos.y, laser[2].pos.x + 510, laser[2].pos.y);
                if (enemy_normal[2].pos.x <= laser[2].pos.x + 510) {
                    enemy_normal[2].life -= lasergun_wea[2].damage;
                    if (enemy_normal[2].life <= 0) {
                        enemy_normal[2].pos.x = 850;
                        enemy_normal[2].life = initial_enemy_life;
                        killed++;
                        coin += 20;
                    }
                }
                if (enemy_mid[2].pos.x <= laser[2].pos.x + 510) {
                    enemy_mid[2].life -= lasergun_wea[2].damage;
                    if (enemy_mid[2].life <= 0) {
                        enemy_mid[2].pos.x = 850;
                        enemy_mid[2].life = initial_enemy2_life;
                        killed++;
                        coin += 30;
                    }
                }
            }
        }
        if (map[3] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_b2 = gcnew Pen(Color::Blue, 2);
            g->DrawEllipse(pen_b2, laser[3].pos.x - 10, laser[3].pos.y - 10, laser[3].radius, laser[3].radius);
            g->DrawLine(pen_b2, laser[3].pos.x, laser[3].pos.y, laser[3].pos.x + 20, laser[3].pos.y);
            if ((system_counter - this->lasergun_wea[3].now_time) % laser[3].shoot_v == 0) {
                Pen^ pen_y4 = gcnew Pen(Color::Yellow, 8);
                g->DrawLine(pen_y4, laser[3].pos.x + 10, laser[3].pos.y, laser[3].pos.x + 510, laser[3].pos.y);
                if (enemy_normal[3].pos.x <= laser[3].pos.x + 510) {
                    enemy_normal[3].life -= lasergun_wea[3].damage;
                    if (enemy_normal[3].life <= 0) {
                        enemy_normal[3].pos.x = 850;
                        enemy_normal[3].life = initial_enemy_life;
                        killed++;
                        coin += 20;
                    }
                }
                if (enemy_mid[3].pos.x <= laser[3].pos.x + 510) {
                    enemy_mid[3].life -= lasergun_wea[3].damage;
                    if (enemy_mid[3].life <= 0) {
                        enemy_mid[3].pos.x = 850;
                        enemy_mid[3].life = initial_enemy2_life;
                        killed++;
                        coin += 30;
                    }
                }
            }
        }
        if (map[4] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_b2 = gcnew Pen(Color::Blue, 2);
            g->DrawEllipse(pen_b2, laser[4].pos.x - 10, laser[4].pos.y - 10, laser[4].radius, laser[4].radius);
            g->DrawLine(pen_b2, laser[4].pos.x, laser[4].pos.y, laser[4].pos.x + 20, laser[4].pos.y);
            if ((system_counter - this->lasergun_wea[4].now_time) % laser[4].shoot_v == 0) {
                Pen^ pen_y4 = gcnew Pen(Color::Yellow, 8);
                g->DrawLine(pen_y4, laser[4].pos.x + 10, laser[4].pos.y, laser[4].pos.x + 510, laser[4].pos.y);
                if (enemy_normal[4].pos.x <= laser[4].pos.x + 510) {
                    enemy_normal[4].life -= lasergun_wea[4].damage;
                    if (enemy_normal[4].life <= 0) {
                        enemy_normal[4].pos.x = 850;
                        enemy_normal[4].life = initial_enemy_life;
                        killed++;
                        coin += 20;
                    }
                }
                if (enemy_mid[4].pos.x <= laser[4].pos.x + 510) {
                    enemy_mid[4].life -= lasergun_wea[4].damage;
                    if (enemy_mid[4].life <= 0) {
                        enemy_mid[4].pos.x = 850;
                        enemy_mid[4].life = initial_enemy2_life;
                        killed++;
                        coin += 30;
                    }
                }
            }
        }
        // machine gun
        if (map[5] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_r = gcnew Pen(Color::Red, 2);
            g->DrawEllipse(pen_r, machine[0].pos.x - 10, machine[0].pos.y - 10, machine[0].radius, machine[0].radius);
            g->DrawLine(pen_r, machine[0].pos.x, machine[0].pos.y, machine[0].pos.x + 20, machine[0].pos.y);
            int notation = 0;
            int interval = 10;
            for (int i = 0; i < 10; i++) {
                if ((system_counter - this->machinegun_wea[notation * 10 + i].now_time) >= 0) {
                    machinegun_wea[notation * 10 + i].V.vx = 26;
                    machinegun_wea[notation * 10 + i].pos.x += machinegun_wea[notation * 10 + i].V.vx;
                    machinegun_wea[notation * 10 + i].pos.y = machine[0].pos.y - 10;
                    Pen^ pen_machinebullet = gcnew Pen(Color::Orange, machinegun_wea[notation * 10 + i].radius);
                    g->DrawEllipse(pen_machinebullet, machinegun_wea[notation * 10 + i].pos.x, machinegun_wea[notation * 10 + i].pos.y, machinegun_wea[notation * 10 + i].radius, machinegun_wea[notation * 10 + i].radius);
                    if (machinegun_wea[notation * 10 + i].pos.x >= 800) {
                        machinegun_wea[notation * 10 + i].pos.x = machine[0].pos.x;
                    }
                }
            }
        }
        if (map[6] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_r = gcnew Pen(Color::Red, 2);
            g->DrawEllipse(pen_r, machine[1].pos.x - 10, machine[1].pos.y - 10, machine[1].radius, machine[1].radius);
            g->DrawLine(pen_r, machine[1].pos.x, machine[1].pos.y, machine[1].pos.x + 20, machine[1].pos.y);
            int notation = 1;
            int interval = 10;
            for (int i = 0; i < 10; i++) {
                if ((system_counter - this->machinegun_wea[notation * 10 + i].now_time) >= 0) {
                    machinegun_wea[notation * 10 + i].V.vx = 26;
                    machinegun_wea[notation * 10 + i].pos.x += machinegun_wea[notation * 10 + i].V.vx;
                    machinegun_wea[notation * 10 + i].pos.y = machine[1].pos.y - 10;
                    Pen^ pen_machinebullet = gcnew Pen(Color::Orange, machinegun_wea[notation * 10 + i].radius);
                    g->DrawEllipse(pen_machinebullet, machinegun_wea[notation * 10 + i].pos.x, machinegun_wea[notation * 10 + i].pos.y, machinegun_wea[notation * 10 + i].radius, machinegun_wea[notation * 10 + i].radius);
                    if (machinegun_wea[notation * 10 + i].pos.x >= 800) {
                        machinegun_wea[notation * 10 + i].pos.x = machine[1].pos.x;
                    }
                }
            }
        }
        if (map[7] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_r = gcnew Pen(Color::Red, 2);
            g->DrawEllipse(pen_r, machine[2].pos.x - 10, machine[2].pos.y - 10, machine[2].radius, machine[2].radius);
            g->DrawLine(pen_r, machine[2].pos.x, machine[2].pos.y, machine[2].pos.x + 20, machine[2].pos.y);
            int notation = 2;
            int interval = 10;
            for (int i = 0; i < 10; i++) {
                if ((system_counter - this->machinegun_wea[notation * 10 + i].now_time) >= 0) {
                    machinegun_wea[notation * 10 + i].V.vx = 26;
                    machinegun_wea[notation * 10 + i].pos.x += machinegun_wea[notation * 10 + i].V.vx;
                    machinegun_wea[notation * 10 + i].pos.y = machine[2].pos.y - 10;
                    Pen^ pen_machinebullet = gcnew Pen(Color::Orange, machinegun_wea[notation * 10 + i].radius);
                    g->DrawEllipse(pen_machinebullet, machinegun_wea[notation * 10 + i].pos.x, machinegun_wea[notation * 10 + i].pos.y, machinegun_wea[notation * 10 + i].radius, machinegun_wea[notation * 10 + i].radius);
                    if (machinegun_wea[notation * 10 + i].pos.x >= 800) {
                        machinegun_wea[notation * 10 + i].pos.x = machine[2].pos.x;
                    }
                }
            }
        }
        if (map[8] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_r = gcnew Pen(Color::Red, 2);
            g->DrawEllipse(pen_r, machine[3].pos.x - 10, machine[3].pos.y - 10, machine[3].radius, machine[3].radius);
            g->DrawLine(pen_r, machine[3].pos.x, machine[3].pos.y, machine[3].pos.x + 20, machine[3].pos.y);
            int notation = 3;
            int interval = 10;
            for (int i = 0; i < 10; i++) {
                if ((system_counter - this->machinegun_wea[notation * 10 + i].now_time) >= 0) {
                    machinegun_wea[notation * 10 + i].V.vx = 26;
                    machinegun_wea[notation * 10 + i].pos.x += machinegun_wea[notation * 10 + i].V.vx;
                    machinegun_wea[notation * 10 + i].pos.y = machine[3].pos.y - 10;
                    Pen^ pen_machinebullet = gcnew Pen(Color::Orange, machinegun_wea[notation * 10 + i].radius);
                    g->DrawEllipse(pen_machinebullet, machinegun_wea[notation * 10 + i].pos.x, machinegun_wea[notation * 10 + i].pos.y, machinegun_wea[notation * 10 + i].radius, machinegun_wea[notation * 10 + i].radius);
                    if (machinegun_wea[notation * 10 + i].pos.x >= 800) {
                        machinegun_wea[notation * 10 + i].pos.x = machine[3].pos.x;
                    }
                }
            }
        }
        if (map[9] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_r = gcnew Pen(Color::Red, 2);
            g->DrawEllipse(pen_r, machine[4].pos.x - 10, machine[4].pos.y - 10, machine[4].radius, machine[4].radius);
            g->DrawLine(pen_r, machine[4].pos.x, machine[4].pos.y, machine[4].pos.x + 20, machine[4].pos.y);
            int notation = 4;
            int interval = 10;
            for (int i = 0; i < 10; i++) {
                if ((system_counter - this->machinegun_wea[notation * 10 + i].now_time) >= 0) {
                    machinegun_wea[notation * 10 + i].V.vx = 26;
                    machinegun_wea[notation * 10 + i].pos.x += machinegun_wea[notation * 10 + i].V.vx;
                    machinegun_wea[notation * 10 + i].pos.y = machine[4].pos.y - 10;
                    Pen^ pen_machinebullet = gcnew Pen(Color::Orange, machinegun_wea[notation * 10 + i].radius);
                    g->DrawEllipse(pen_machinebullet, machinegun_wea[notation * 10 + i].pos.x, machinegun_wea[notation * 10 + i].pos.y, machinegun_wea[notation * 10 + i].radius, machinegun_wea[notation * 10 + i].radius);
                    if (machinegun_wea[notation * 10 + i].pos.x >= 800) {
                        machinegun_wea[notation * 10 + i].pos.x = machine[4].pos.x;
                    }
                }
            }
        }
        // cannon
        if (map[10] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_p = gcnew Pen(Color::Purple, 2);
            int notation = 0;
            g->DrawEllipse(pen_p, Cannon[notation].pos.x - 10, Cannon[notation].pos.y - 10, Cannon[notation].radius, Cannon[notation].radius);
            g->DrawLine(pen_p, Cannon[notation].pos.x, Cannon[notation].pos.y, Cannon[notation].pos.x + 20, Cannon[notation].pos.y);
            cannon_wea[notation].V.vx = 10;
            cannon_wea[notation].pos.x += cannon_wea[notation].V.vx;
            cannon_wea[notation].pos.y = Cannon[notation].pos.y - 10;
            Pen^ pen_cannonbullet = gcnew Pen(Color::Black, 20);
            g->DrawEllipse(pen_cannonbullet, (int)cannon_wea[notation].pos.x, (int)cannon_wea[notation].pos.y, 20, 20);
            if (cannon_wea[notation].pos.x >= 800) {
                cannon_wea[notation].pos.x = Cannon[notation].pos.x;
            }
        }
        if (map[11] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_p = gcnew Pen(Color::Purple, 2);
            int notation = 1;
            g->DrawEllipse(pen_p, Cannon[notation].pos.x - 10, Cannon[notation].pos.y - 10, Cannon[notation].radius, Cannon[notation].radius);
            g->DrawLine(pen_p, Cannon[notation].pos.x, Cannon[notation].pos.y, Cannon[notation].pos.x + 20, Cannon[notation].pos.y);
            cannon_wea[notation].V.vx = 10;
            cannon_wea[notation].pos.x += cannon_wea[notation].V.vx;
            cannon_wea[notation].pos.y = Cannon[notation].pos.y - 10;
            Pen^ pen_cannonbullet = gcnew Pen(Color::Black, 20);
            g->DrawEllipse(pen_cannonbullet, (int)cannon_wea[notation].pos.x, (int)cannon_wea[notation].pos.y, 20, 20);
            if (cannon_wea[notation].pos.x >= 800) {
                cannon_wea[notation].pos.x = Cannon[notation].pos.x;
            }
        }
        if (map[12] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_p = gcnew Pen(Color::Purple, 2);
            int notation = 2;
            g->DrawEllipse(pen_p, Cannon[notation].pos.x - 10, Cannon[notation].pos.y - 10, Cannon[notation].radius, Cannon[notation].radius);
            g->DrawLine(pen_p, Cannon[notation].pos.x, Cannon[notation].pos.y, Cannon[notation].pos.x + 20, Cannon[notation].pos.y);
            cannon_wea[notation].V.vx = 10;
            cannon_wea[notation].pos.x += cannon_wea[notation].V.vx;
            cannon_wea[notation].pos.y = Cannon[notation].pos.y - 10;
            Pen^ pen_cannonbullet = gcnew Pen(Color::Black, 20);
            g->DrawEllipse(pen_cannonbullet, (int)cannon_wea[notation].pos.x, (int)cannon_wea[notation].pos.y, 20, 20);
            if (cannon_wea[notation].pos.x >= 800) {
                cannon_wea[notation].pos.x = Cannon[notation].pos.x;
            }
        }
        if (map[13] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_p = gcnew Pen(Color::Purple, 2);
            int notation = 3;
            g->DrawEllipse(pen_p, Cannon[notation].pos.x - 10, Cannon[notation].pos.y - 10, Cannon[notation].radius, Cannon[notation].radius);
            g->DrawLine(pen_p, Cannon[notation].pos.x, Cannon[notation].pos.y, Cannon[notation].pos.x + 20, Cannon[notation].pos.y);
            cannon_wea[notation].V.vx = 10;
            cannon_wea[notation].pos.x += cannon_wea[notation].V.vx;
            cannon_wea[notation].pos.y = Cannon[notation].pos.y - 10;
            Pen^ pen_cannonbullet = gcnew Pen(Color::Black, 20);
            g->DrawEllipse(pen_cannonbullet, (int)cannon_wea[notation].pos.x, (int)cannon_wea[notation].pos.y, 20, 20);
            if (cannon_wea[notation].pos.x >= 800) {
                cannon_wea[notation].pos.x = Cannon[notation].pos.x;
            }
        }
        if (map[14] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_p = gcnew Pen(Color::Purple, 2);
            int notation = 4;
            g->DrawEllipse(pen_p, Cannon[notation].pos.x - 10, Cannon[notation].pos.y - 10, Cannon[notation].radius, Cannon[notation].radius);
            g->DrawLine(pen_p, Cannon[notation].pos.x, Cannon[notation].pos.y, Cannon[notation].pos.x + 20, Cannon[notation].pos.y);
            cannon_wea[notation].V.vx = 10;
            cannon_wea[notation].pos.x += cannon_wea[notation].V.vx;
            cannon_wea[notation].pos.y = Cannon[notation].pos.y - 10;
            Pen^ pen_cannonbullet = gcnew Pen(Color::Black, 20);
            g->DrawEllipse(pen_cannonbullet, (int)cannon_wea[notation].pos.x, (int)cannon_wea[notation].pos.y, 20, 20);
            if (cannon_wea[notation].pos.x >= 800) {
                cannon_wea[notation].pos.x = Cannon[notation].pos.x;
            }
        }
        // landmine
        if (map[15] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, 15);
            int notation = 0;
            g->DrawEllipse(pen_k, Landmine[notation].pos.x + 10, Landmine[notation].pos.y - 10, Landmine[notation].radius, Landmine[notation].radius);
        }
        if (map[16] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, 15);
            int notation = 1;
            g->DrawEllipse(pen_k, Landmine[notation].pos.x + 10, Landmine[notation].pos.y - 10, Landmine[notation].radius, Landmine[notation].radius);
        }
        if (map[17] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, 15);
            int notation = 2;
            g->DrawEllipse(pen_k, Landmine[notation].pos.x + 10, Landmine[notation].pos.y - 10, Landmine[notation].radius, Landmine[notation].radius);
        }
        if (map[18] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, 15);
            int notation = 3;
            g->DrawEllipse(pen_k, Landmine[notation].pos.x + 10, Landmine[notation].pos.y - 10, Landmine[notation].radius, Landmine[notation].radius);
        }
        if (map[19] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, 15);
            int notation = 4;
            g->DrawEllipse(pen_k, Landmine[notation].pos.x + 10, Landmine[notation].pos.y - 10, Landmine[notation].radius, Landmine[notation].radius);
        }
        // bomb
        if (map[20] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_br = gcnew Pen(Color::Brown, 20 + (system_counter - Bomb[0].now_time) * 0.5);
            int notation = 0;
            g->DrawEllipse(pen_br, Bomb[notation].pos.x + 10, Bomb[notation].pos.y - 10, Bomb[notation].radius + (system_counter - Bomb[notation].now_time) * 0.5, Bomb[notation].radius + (system_counter - Bomb[notation].now_time) * 0.5);
        }
        if (map[21] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_br = gcnew Pen(Color::Brown, 20 + (system_counter - Bomb[1].now_time) * 0.5);
            int notation = 1;
            g->DrawEllipse(pen_br, Bomb[notation].pos.x + 10, Bomb[notation].pos.y - 10, Bomb[notation].radius + (system_counter - Bomb[notation].now_time) * 0.5, Bomb[notation].radius + (system_counter - Bomb[notation].now_time) * 0.5);
        }
        if (map[22] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_br = gcnew Pen(Color::Brown, 20 + (system_counter - Bomb[2].now_time) * 0.5);
            int notation = 2;
            g->DrawEllipse(pen_br, Bomb[notation].pos.x + 10, Bomb[notation].pos.y - 10, Bomb[notation].radius + (system_counter - Bomb[notation].now_time) * 0.5, Bomb[notation].radius + (system_counter - Bomb[notation].now_time) * 0.5);
        }
        if (map[23] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_br = gcnew Pen(Color::Brown, 20 + (system_counter - Bomb[3].now_time) * 0.5);
            int notation = 3;
            g->DrawEllipse(pen_br, Bomb[notation].pos.x + 10, Bomb[notation].pos.y - 10, Bomb[notation].radius + (system_counter - Bomb[notation].now_time) * 0.5, Bomb[notation].radius + (system_counter - Bomb[notation].now_time) * 0.5);
        }
        if (map[24] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_br = gcnew Pen(Color::Brown, 20 + (system_counter - Bomb[4].now_time) * 0.5);
            int notation = 4;
            g->DrawEllipse(pen_br, Bomb[notation].pos.x + 10, Bomb[notation].pos.y - 10, Bomb[notation].radius + (system_counter - Bomb[notation].now_time) * 0.5, Bomb[notation].radius + (system_counter - Bomb[notation].now_time) * 0.5);
        }
        // enemy_normal
        if (enemy_normal[0].enable == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, enemy_normal[0].radius);
            g->DrawEllipse(pen_k, enemy_normal[0].pos.x - 10, enemy_normal[0].pos.y - 10, enemy_normal[0].radius, enemy_normal[0].radius);
        }
        if (enemy_normal[1].enable == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, enemy_normal[1].radius);
            g->DrawEllipse(pen_k, enemy_normal[1].pos.x - 10, enemy_normal[1].pos.y - 10, enemy_normal[1].radius, enemy_normal[1].radius);
        }
        if (enemy_normal[2].enable == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, enemy_normal[2].radius);
            g->DrawEllipse(pen_k, enemy_normal[2].pos.x - 10, enemy_normal[2].pos.y - 10, enemy_normal[2].radius, enemy_normal[2].radius);
        }
        if (enemy_normal[3].enable == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, enemy_normal[3].radius);
            g->DrawEllipse(pen_k, enemy_normal[3].pos.x - 10, enemy_normal[3].pos.y - 10, enemy_normal[3].radius, enemy_normal[3].radius);
        }
        if (enemy_normal[4].enable == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, enemy_normal[4].radius);
            g->DrawEllipse(pen_k, enemy_normal[4].pos.x - 10, enemy_normal[4].pos.y - 10, enemy_normal[4].radius, enemy_normal[4].radius);
        }
        // enemy_mid
        if (enemy_mid[0].enable == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_or = gcnew Pen(Color::Orange, enemy_mid[0].radius);
            g->DrawEllipse(pen_or, enemy_mid[0].pos.x - 10, enemy_mid[0].pos.y - 10, enemy_mid[0].radius, enemy_mid[0].radius);
        }
        if (enemy_mid[1].enable == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_or = gcnew Pen(Color::Orange, enemy_mid[1].radius);
            g->DrawEllipse(pen_or, enemy_mid[1].pos.x - 10, enemy_mid[1].pos.y - 10, enemy_mid[1].radius, enemy_mid[1].radius);
        }
        if (enemy_mid[2].enable == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_or = gcnew Pen(Color::Orange, enemy_mid[2].radius);
            g->DrawEllipse(pen_or, enemy_mid[2].pos.x - 10, enemy_mid[2].pos.y - 10, enemy_mid[2].radius, enemy_mid[2].radius);
        }
        if (enemy_mid[3].enable == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_or = gcnew Pen(Color::Orange, enemy_normal[3].radius);
            g->DrawEllipse(pen_or, enemy_mid[3].pos.x - 10, enemy_mid[3].pos.y - 10, enemy_mid[3].radius, enemy_mid[3].radius);
        }
        if (enemy_mid[4].enable == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_or = gcnew Pen(Color::Orange, enemy_mid[4].radius);
            g->DrawEllipse(pen_or, enemy_mid[4].pos.x - 10, enemy_mid[4].pos.y - 10, enemy_mid[4].radius, enemy_mid[4].radius);
        }
    }
    private: System::Void playgameform_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        // �b�ƹ��I���ƥ󤤨��o�y��
        mouseX = static_cast<float>(e->X);
        mouseY = static_cast<float>(e->Y);
    }

           // �b�ݭn���a��I�s Invalidate() ��Ĳ�o pictureBox1_Paint �ƥ�



           /// <summary>
        /// �]�p�u��һݪ��ܼơC
        /// </summary>


#pragma region Windows Form Designer generated code
        /// <summary>
        /// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
        /// �o�Ӥ�k�����e�C
        /// </summary>
           void InitializeComponent(void)
           {
               this->components = (gcnew System::ComponentModel::Container());
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(playgameform2::typeid));
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
               this->button2 = (gcnew System::Windows::Forms::Button());
               this->button3 = (gcnew System::Windows::Forms::Button());
               this->button4 = (gcnew System::Windows::Forms::Button());
               this->button5 = (gcnew System::Windows::Forms::Button());
               this->button6 = (gcnew System::Windows::Forms::Button());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
               this->button7 = (gcnew System::Windows::Forms::Button());
               this->button8 = (gcnew System::Windows::Forms::Button());
               this->button9 = (gcnew System::Windows::Forms::Button());
               this->button10 = (gcnew System::Windows::Forms::Button());
               this->button11 = (gcnew System::Windows::Forms::Button());
               this->button12 = (gcnew System::Windows::Forms::Button());
               this->button13 = (gcnew System::Windows::Forms::Button());
               this->button14 = (gcnew System::Windows::Forms::Button());
               this->button15 = (gcnew System::Windows::Forms::Button());
               this->button16 = (gcnew System::Windows::Forms::Button());
               this->button17 = (gcnew System::Windows::Forms::Button());
               this->button18 = (gcnew System::Windows::Forms::Button());
               this->button19 = (gcnew System::Windows::Forms::Button());
               this->button20 = (gcnew System::Windows::Forms::Button());
               this->button21 = (gcnew System::Windows::Forms::Button());
               this->button22 = (gcnew System::Windows::Forms::Button());
               this->button23 = (gcnew System::Windows::Forms::Button());
               this->button24 = (gcnew System::Windows::Forms::Button());
               this->button25 = (gcnew System::Windows::Forms::Button());
               this->button26 = (gcnew System::Windows::Forms::Button());
               this->button27 = (gcnew System::Windows::Forms::Button());
               this->button28 = (gcnew System::Windows::Forms::Button());
               this->button29 = (gcnew System::Windows::Forms::Button());
               this->button30 = (gcnew System::Windows::Forms::Button());
               this->button31 = (gcnew System::Windows::Forms::Button());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->label4 = (gcnew System::Windows::Forms::Label());
               this->label5 = (gcnew System::Windows::Forms::Label());
               this->label6 = (gcnew System::Windows::Forms::Label());
               this->label7 = (gcnew System::Windows::Forms::Label());
               this->label8 = (gcnew System::Windows::Forms::Label());
               this->label9 = (gcnew System::Windows::Forms::Label());
               this->label10 = (gcnew System::Windows::Forms::Label());
               this->label11 = (gcnew System::Windows::Forms::Label());
               this->label12 = (gcnew System::Windows::Forms::Label());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
               this->SuspendLayout();
               // 
               // button1
               // 
               this->button1->BackColor = System::Drawing::Color::Gold;
               this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(136)));
               this->button1->Location = System::Drawing::Point(782, 0);
               this->button1->Margin = System::Windows::Forms::Padding(2);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(103, 34);
               this->button1->TabIndex = 0;
               this->button1->Text = L"back";
               this->button1->UseVisualStyleBackColor = false;
               this->button1->Click += gcnew System::EventHandler(this, &playgameform2::button1_Click);
               // 
               // pictureBox1
               // 
               this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
               this->pictureBox1->Location = System::Drawing::Point(1, 77);
               this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
               this->pictureBox1->Name = L"pictureBox1";
               this->pictureBox1->Size = System::Drawing::Size(884, 394);
               this->pictureBox1->TabIndex = 1;
               this->pictureBox1->TabStop = false;
               this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &playgameform2::pictureBox1_Paint);
               // 
               // button2
               // 
               this->button2->Location = System::Drawing::Point(174, 12);
               this->button2->Name = L"button2";
               this->button2->Size = System::Drawing::Size(62, 49);
               this->button2->TabIndex = 2;
               this->button2->Text = L"laser";
               this->button2->UseVisualStyleBackColor = true;
               this->button2->Click += gcnew System::EventHandler(this, &playgameform2::button2_Click);
               // 
               // button3
               // 
               this->button3->Location = System::Drawing::Point(270, 12);
               this->button3->Name = L"button3";
               this->button3->Size = System::Drawing::Size(62, 49);
               this->button3->TabIndex = 3;
               this->button3->Text = L"machine";
               this->button3->UseVisualStyleBackColor = true;
               this->button3->Click += gcnew System::EventHandler(this, &playgameform2::button3_Click);
               // 
               // button4
               // 
               this->button4->Location = System::Drawing::Point(360, 12);
               this->button4->Name = L"button4";
               this->button4->Size = System::Drawing::Size(62, 49);
               this->button4->TabIndex = 4;
               this->button4->Text = L"cannon";
               this->button4->UseVisualStyleBackColor = true;
               this->button4->Click += gcnew System::EventHandler(this, &playgameform2::button4_Click);
               // 
               // button5
               // 
               this->button5->Location = System::Drawing::Point(448, 12);
               this->button5->Name = L"button5";
               this->button5->Size = System::Drawing::Size(62, 49);
               this->button5->TabIndex = 5;
               this->button5->Text = L"landmine";
               this->button5->UseVisualStyleBackColor = true;
               this->button5->Click += gcnew System::EventHandler(this, &playgameform2::button5_Click);
               // 
               // button6
               // 
               this->button6->Location = System::Drawing::Point(532, 12);
               this->button6->Name = L"button6";
               this->button6->Size = System::Drawing::Size(62, 49);
               this->button6->TabIndex = 6;
               this->button6->Text = L"bomb";
               this->button6->UseVisualStyleBackColor = true;
               this->button6->Click += gcnew System::EventHandler(this, &playgameform2::button6_Click);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
               this->label1->Location = System::Drawing::Point(36, 20);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(79, 29);
               this->label1->TabIndex = 7;
               this->label1->Text = L"label1";
               // 
               // timer1
               // 
               this->timer1->Enabled = true;
               this->timer1->Tick += gcnew System::EventHandler(this, &playgameform2::timer1_Tick);
               // 
               // button7
               // 
               this->button7->BackColor = System::Drawing::Color::YellowGreen;
               this->button7->Location = System::Drawing::Point(174, 94);
               this->button7->Name = L"button7";
               this->button7->Size = System::Drawing::Size(62, 53);
               this->button7->TabIndex = 8;
               this->button7->Text = L"button7";
               this->button7->UseVisualStyleBackColor = false;
               this->button7->Visible = false;
               this->button7->Click += gcnew System::EventHandler(this, &playgameform2::button7_Click);
               // 
               // button8
               // 
               this->button8->BackColor = System::Drawing::Color::YellowGreen;
               this->button8->Location = System::Drawing::Point(174, 173);
               this->button8->Name = L"button8";
               this->button8->Size = System::Drawing::Size(62, 53);
               this->button8->TabIndex = 9;
               this->button8->Text = L"button8";
               this->button8->UseVisualStyleBackColor = false;
               this->button8->Visible = false;
               this->button8->Click += gcnew System::EventHandler(this, &playgameform2::button8_Click);
               // 
               // button9
               // 
               this->button9->BackColor = System::Drawing::Color::YellowGreen;
               this->button9->Location = System::Drawing::Point(174, 248);
               this->button9->Name = L"button9";
               this->button9->Size = System::Drawing::Size(62, 53);
               this->button9->TabIndex = 10;
               this->button9->Text = L"button9";
               this->button9->UseVisualStyleBackColor = false;
               this->button9->Visible = false;
               this->button9->Click += gcnew System::EventHandler(this, &playgameform2::button9_Click);
               // 
               // button10
               // 
               this->button10->BackColor = System::Drawing::Color::YellowGreen;
               this->button10->Location = System::Drawing::Point(174, 319);
               this->button10->Name = L"button10";
               this->button10->Size = System::Drawing::Size(62, 53);
               this->button10->TabIndex = 11;
               this->button10->Text = L"button10";
               this->button10->UseVisualStyleBackColor = false;
               this->button10->Visible = false;
               this->button10->Click += gcnew System::EventHandler(this, &playgameform2::button10_Click);
               // 
               // button11
               // 
               this->button11->BackColor = System::Drawing::Color::YellowGreen;
               this->button11->Location = System::Drawing::Point(174, 392);
               this->button11->Name = L"button11";
               this->button11->Size = System::Drawing::Size(62, 53);
               this->button11->TabIndex = 12;
               this->button11->Text = L"button11";
               this->button11->UseVisualStyleBackColor = false;
               this->button11->Visible = false;
               this->button11->Click += gcnew System::EventHandler(this, &playgameform2::button11_Click);
               // 
               // button12
               // 
               this->button12->BackColor = System::Drawing::Color::YellowGreen;
               this->button12->Location = System::Drawing::Point(270, 94);
               this->button12->Name = L"button12";
               this->button12->Size = System::Drawing::Size(62, 53);
               this->button12->TabIndex = 13;
               this->button12->Text = L"button12";
               this->button12->UseVisualStyleBackColor = false;
               this->button12->Visible = false;
               this->button12->Click += gcnew System::EventHandler(this, &playgameform2::button12_Click);
               // 
               // button13
               // 
               this->button13->BackColor = System::Drawing::Color::YellowGreen;
               this->button13->Location = System::Drawing::Point(270, 173);
               this->button13->Name = L"button13";
               this->button13->Size = System::Drawing::Size(62, 53);
               this->button13->TabIndex = 14;
               this->button13->Text = L"button13";
               this->button13->UseVisualStyleBackColor = false;
               this->button13->Visible = false;
               this->button13->Click += gcnew System::EventHandler(this, &playgameform2::button13_Click);
               // 
               // button14
               // 
               this->button14->BackColor = System::Drawing::Color::YellowGreen;
               this->button14->Location = System::Drawing::Point(270, 248);
               this->button14->Name = L"button14";
               this->button14->Size = System::Drawing::Size(62, 53);
               this->button14->TabIndex = 15;
               this->button14->Text = L"button14";
               this->button14->UseVisualStyleBackColor = false;
               this->button14->Visible = false;
               this->button14->Click += gcnew System::EventHandler(this, &playgameform2::button14_Click);
               // 
               // button15
               // 
               this->button15->BackColor = System::Drawing::Color::YellowGreen;
               this->button15->Location = System::Drawing::Point(270, 319);
               this->button15->Name = L"button15";
               this->button15->Size = System::Drawing::Size(62, 53);
               this->button15->TabIndex = 16;
               this->button15->Text = L"button15";
               this->button15->UseVisualStyleBackColor = false;
               this->button15->Visible = false;
               this->button15->Click += gcnew System::EventHandler(this, &playgameform2::button15_Click);
               // 
               // button16
               // 
               this->button16->BackColor = System::Drawing::Color::YellowGreen;
               this->button16->Location = System::Drawing::Point(270, 392);
               this->button16->Name = L"button16";
               this->button16->Size = System::Drawing::Size(62, 53);
               this->button16->TabIndex = 17;
               this->button16->Text = L"button16";
               this->button16->UseVisualStyleBackColor = false;
               this->button16->Visible = false;
               this->button16->Click += gcnew System::EventHandler(this, &playgameform2::button16_Click);
               // 
               // button17
               // 
               this->button17->BackColor = System::Drawing::Color::YellowGreen;
               this->button17->Location = System::Drawing::Point(360, 94);
               this->button17->Name = L"button17";
               this->button17->Size = System::Drawing::Size(62, 53);
               this->button17->TabIndex = 18;
               this->button17->Text = L"button17";
               this->button17->UseVisualStyleBackColor = false;
               this->button17->Visible = false;
               this->button17->Click += gcnew System::EventHandler(this, &playgameform2::button17_Click);
               // 
               // button18
               // 
               this->button18->BackColor = System::Drawing::Color::YellowGreen;
               this->button18->Location = System::Drawing::Point(360, 173);
               this->button18->Name = L"button18";
               this->button18->Size = System::Drawing::Size(62, 53);
               this->button18->TabIndex = 19;
               this->button18->Text = L"button18";
               this->button18->UseVisualStyleBackColor = false;
               this->button18->Visible = false;
               this->button18->Click += gcnew System::EventHandler(this, &playgameform2::button18_Click);
               // 
               // button19
               // 
               this->button19->BackColor = System::Drawing::Color::YellowGreen;
               this->button19->Location = System::Drawing::Point(360, 248);
               this->button19->Name = L"button19";
               this->button19->Size = System::Drawing::Size(62, 53);
               this->button19->TabIndex = 20;
               this->button19->Text = L"button19";
               this->button19->UseVisualStyleBackColor = false;
               this->button19->Visible = false;
               this->button19->Click += gcnew System::EventHandler(this, &playgameform2::button19_Click);
               // 
               // button20
               // 
               this->button20->BackColor = System::Drawing::Color::YellowGreen;
               this->button20->Location = System::Drawing::Point(360, 319);
               this->button20->Name = L"button20";
               this->button20->Size = System::Drawing::Size(62, 53);
               this->button20->TabIndex = 21;
               this->button20->Text = L"button20";
               this->button20->UseVisualStyleBackColor = false;
               this->button20->Visible = false;
               this->button20->Click += gcnew System::EventHandler(this, &playgameform2::button20_Click);
               // 
               // button21
               // 
               this->button21->BackColor = System::Drawing::Color::YellowGreen;
               this->button21->Location = System::Drawing::Point(360, 392);
               this->button21->Name = L"button21";
               this->button21->Size = System::Drawing::Size(62, 53);
               this->button21->TabIndex = 22;
               this->button21->Text = L"button21";
               this->button21->UseVisualStyleBackColor = false;
               this->button21->Visible = false;
               this->button21->Click += gcnew System::EventHandler(this, &playgameform2::button21_Click);
               // 
               // button22
               // 
               this->button22->BackColor = System::Drawing::Color::YellowGreen;
               this->button22->Location = System::Drawing::Point(448, 94);
               this->button22->Name = L"button22";
               this->button22->Size = System::Drawing::Size(62, 53);
               this->button22->TabIndex = 23;
               this->button22->Text = L"button22";
               this->button22->UseVisualStyleBackColor = false;
               this->button22->Visible = false;
               this->button22->Click += gcnew System::EventHandler(this, &playgameform2::button22_Click);
               // 
               // button23
               // 
               this->button23->BackColor = System::Drawing::Color::YellowGreen;
               this->button23->Location = System::Drawing::Point(448, 173);
               this->button23->Name = L"button23";
               this->button23->Size = System::Drawing::Size(62, 53);
               this->button23->TabIndex = 24;
               this->button23->Text = L"button23";
               this->button23->UseVisualStyleBackColor = false;
               this->button23->Visible = false;
               this->button23->Click += gcnew System::EventHandler(this, &playgameform2::button23_Click);
               // 
               // button24
               // 
               this->button24->BackColor = System::Drawing::Color::YellowGreen;
               this->button24->Location = System::Drawing::Point(448, 248);
               this->button24->Name = L"button24";
               this->button24->Size = System::Drawing::Size(62, 53);
               this->button24->TabIndex = 25;
               this->button24->Text = L"button24";
               this->button24->UseVisualStyleBackColor = false;
               this->button24->Visible = false;
               this->button24->Click += gcnew System::EventHandler(this, &playgameform2::button24_Click);
               // 
               // button25
               // 
               this->button25->BackColor = System::Drawing::Color::YellowGreen;
               this->button25->Location = System::Drawing::Point(448, 319);
               this->button25->Name = L"button25";
               this->button25->Size = System::Drawing::Size(62, 53);
               this->button25->TabIndex = 26;
               this->button25->Text = L"button25";
               this->button25->UseVisualStyleBackColor = false;
               this->button25->Visible = false;
               this->button25->Click += gcnew System::EventHandler(this, &playgameform2::button25_Click);
               // 
               // button26
               // 
               this->button26->BackColor = System::Drawing::Color::YellowGreen;
               this->button26->Location = System::Drawing::Point(448, 392);
               this->button26->Name = L"button26";
               this->button26->Size = System::Drawing::Size(62, 53);
               this->button26->TabIndex = 27;
               this->button26->Text = L"button26";
               this->button26->UseVisualStyleBackColor = false;
               this->button26->Visible = false;
               this->button26->Click += gcnew System::EventHandler(this, &playgameform2::button26_Click);
               // 
               // button27
               // 
               this->button27->BackColor = System::Drawing::Color::YellowGreen;
               this->button27->Location = System::Drawing::Point(532, 94);
               this->button27->Name = L"button27";
               this->button27->Size = System::Drawing::Size(62, 53);
               this->button27->TabIndex = 28;
               this->button27->Text = L"button27";
               this->button27->UseVisualStyleBackColor = false;
               this->button27->Visible = false;
               this->button27->Click += gcnew System::EventHandler(this, &playgameform2::button27_Click);
               // 
               // button28
               // 
               this->button28->BackColor = System::Drawing::Color::YellowGreen;
               this->button28->Location = System::Drawing::Point(532, 173);
               this->button28->Name = L"button28";
               this->button28->Size = System::Drawing::Size(62, 53);
               this->button28->TabIndex = 29;
               this->button28->Text = L"button28";
               this->button28->UseVisualStyleBackColor = false;
               this->button28->Visible = false;
               this->button28->Click += gcnew System::EventHandler(this, &playgameform2::button28_Click);
               // 
               // button29
               // 
               this->button29->BackColor = System::Drawing::Color::YellowGreen;
               this->button29->Location = System::Drawing::Point(532, 248);
               this->button29->Name = L"button29";
               this->button29->Size = System::Drawing::Size(62, 53);
               this->button29->TabIndex = 30;
               this->button29->Text = L"button29";
               this->button29->UseVisualStyleBackColor = false;
               this->button29->Visible = false;
               this->button29->Click += gcnew System::EventHandler(this, &playgameform2::button29_Click);
               // 
               // button30
               // 
               this->button30->BackColor = System::Drawing::Color::YellowGreen;
               this->button30->Location = System::Drawing::Point(532, 319);
               this->button30->Name = L"button30";
               this->button30->Size = System::Drawing::Size(62, 53);
               this->button30->TabIndex = 31;
               this->button30->Text = L"button30";
               this->button30->UseVisualStyleBackColor = false;
               this->button30->Visible = false;
               this->button30->Click += gcnew System::EventHandler(this, &playgameform2::button30_Click);
               // 
               // button31
               // 
               this->button31->BackColor = System::Drawing::Color::YellowGreen;
               this->button31->Location = System::Drawing::Point(532, 392);
               this->button31->Name = L"button31";
               this->button31->Size = System::Drawing::Size(62, 53);
               this->button31->TabIndex = 32;
               this->button31->Text = L"button31";
               this->button31->UseVisualStyleBackColor = false;
               this->button31->Visible = false;
               this->button31->Click += gcnew System::EventHandler(this, &playgameform2::button31_Click);
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->BackColor = System::Drawing::Color::Black;
               this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
               this->label2->ForeColor = System::Drawing::Color::White;
               this->label2->Location = System::Drawing::Point(819, 114);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(93, 20);
               this->label2->TabIndex = 33;
               this->label2->Text = L"(´・ω・`)";
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->BackColor = System::Drawing::Color::Black;
               this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
               this->label3->ForeColor = System::Drawing::Color::White;
               this->label3->Location = System::Drawing::Point(819, 195);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(93, 20);
               this->label3->TabIndex = 34;
               this->label3->Text = L"(´・ω・`)";
               // 
               // label4
               // 
               this->label4->AutoSize = true;
               this->label4->BackColor = System::Drawing::Color::Black;
               this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
               this->label4->ForeColor = System::Drawing::Color::White;
               this->label4->Location = System::Drawing::Point(819, 270);
               this->label4->Name = L"label4";
               this->label4->Size = System::Drawing::Size(93, 20);
               this->label4->TabIndex = 35;
               this->label4->Text = L"(´・ω・`)";
               // 
               // label5
               // 
               this->label5->AutoSize = true;
               this->label5->BackColor = System::Drawing::Color::Black;
               this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
               this->label5->ForeColor = System::Drawing::Color::White;
               this->label5->Location = System::Drawing::Point(819, 340);
               this->label5->Name = L"label5";
               this->label5->Size = System::Drawing::Size(93, 20);
               this->label5->TabIndex = 36;
               this->label5->Text = L"(´・ω・`)";
               // 
               // label6
               // 
               this->label6->AutoSize = true;
               this->label6->BackColor = System::Drawing::Color::Black;
               this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
               this->label6->ForeColor = System::Drawing::Color::White;
               this->label6->Location = System::Drawing::Point(819, 413);
               this->label6->Name = L"label6";
               this->label6->Size = System::Drawing::Size(93, 20);
               this->label6->TabIndex = 37;
               this->label6->Text = L"(´・ω・`)";
               // 
               // label7
               // 
               this->label7->AutoSize = true;
               this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
               this->label7->Location = System::Drawing::Point(665, 30);
               this->label7->Name = L"label7";
               this->label7->Size = System::Drawing::Size(64, 24);
               this->label7->TabIndex = 38;
               this->label7->Text = L"label7";
               // 
               // label8
               // 
               this->label8->AutoSize = true;
               this->label8->BackColor = System::Drawing::Color::Orange;
               this->label8->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
               this->label8->ForeColor = System::Drawing::Color::Blue;
               this->label8->Location = System::Drawing::Point(819, 114);
               this->label8->Name = L"label8";
               this->label8->Size = System::Drawing::Size(84, 20);
               this->label8->TabIndex = 39;
               this->label8->Text = L"(*´･д･)\?";
               // 
               // label9
               // 
               this->label9->AutoSize = true;
               this->label9->BackColor = System::Drawing::Color::Orange;
               this->label9->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
               this->label9->ForeColor = System::Drawing::Color::Blue;
               this->label9->Location = System::Drawing::Point(819, 195);
               this->label9->Name = L"label9";
               this->label9->Size = System::Drawing::Size(84, 20);
               this->label9->TabIndex = 40;
               this->label9->Text = L"(*´･д･)\?";
               // 
               // label10
               // 
               this->label10->AutoSize = true;
               this->label10->BackColor = System::Drawing::Color::Orange;
               this->label10->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
               this->label10->ForeColor = System::Drawing::Color::Blue;
               this->label10->Location = System::Drawing::Point(819, 270);
               this->label10->Name = L"label10";
               this->label10->Size = System::Drawing::Size(84, 20);
               this->label10->TabIndex = 41;
               this->label10->Text = L"(*´･д･)\?";
               // 
               // label11
               // 
               this->label11->AutoSize = true;
               this->label11->BackColor = System::Drawing::Color::Orange;
               this->label11->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
               this->label11->ForeColor = System::Drawing::Color::Blue;
               this->label11->Location = System::Drawing::Point(819, 340);
               this->label11->Name = L"label11";
               this->label11->Size = System::Drawing::Size(84, 20);
               this->label11->TabIndex = 42;
               this->label11->Text = L"(*´･д･)\?";
               // 
               // label12
               // 
               this->label12->AutoSize = true;
               this->label12->BackColor = System::Drawing::Color::Orange;
               this->label12->Font = (gcnew System::Drawing::Font(L"新細明體", 10));
               this->label12->ForeColor = System::Drawing::Color::Blue;
               this->label12->Location = System::Drawing::Point(819, 413);
               this->label12->Name = L"label12";
               this->label12->Size = System::Drawing::Size(84, 20);
               this->label12->TabIndex = 43;
               this->label12->Text = L"(*´･д･)\?";
               // 
               // playgameform2
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::Color::LemonChiffon;
               this->ClientSize = System::Drawing::Size(884, 522);
               this->Controls->Add(this->label12);
               this->Controls->Add(this->label11);
               this->Controls->Add(this->label10);
               this->Controls->Add(this->label9);
               this->Controls->Add(this->label8);
               this->Controls->Add(this->label7);
               this->Controls->Add(this->label6);
               this->Controls->Add(this->label5);
               this->Controls->Add(this->label4);
               this->Controls->Add(this->label3);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->button31);
               this->Controls->Add(this->button30);
               this->Controls->Add(this->button29);
               this->Controls->Add(this->button28);
               this->Controls->Add(this->button27);
               this->Controls->Add(this->button26);
               this->Controls->Add(this->button25);
               this->Controls->Add(this->button24);
               this->Controls->Add(this->button23);
               this->Controls->Add(this->button22);
               this->Controls->Add(this->button21);
               this->Controls->Add(this->button20);
               this->Controls->Add(this->button19);
               this->Controls->Add(this->button18);
               this->Controls->Add(this->button17);
               this->Controls->Add(this->button16);
               this->Controls->Add(this->button15);
               this->Controls->Add(this->button14);
               this->Controls->Add(this->button13);
               this->Controls->Add(this->button12);
               this->Controls->Add(this->button11);
               this->Controls->Add(this->button10);
               this->Controls->Add(this->button9);
               this->Controls->Add(this->button8);
               this->Controls->Add(this->button7);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->button6);
               this->Controls->Add(this->button5);
               this->Controls->Add(this->button4);
               this->Controls->Add(this->button3);
               this->Controls->Add(this->button2);
               this->Controls->Add(this->pictureBox1);
               this->Controls->Add(this->button1);
               this->Margin = System::Windows::Forms::Padding(2);
               this->Name = L"playgameform2";
               this->Text = L"gaming";
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }

           void text_displayer() {
               this->label1->Text = ("Money: " + Convert::ToString(coin));
               this->label7->Text = ("Killed number: " + Convert::ToString(killed));
           }

           void Motion() {
               //enemy motion 
               for (int i = 0; i < 5; i++) {
                   int layer = -1;
                   bool isbreak = false;
                   bool isbreak2 = false;
                   for (int j = 0; j < 5; j++) {
                       if (map[5 * j + i]) {
                           if (j == 0 && enemy_normal[i].pos.x - 50 == laser[i].pos.x) {
                               enemy_normal[i].pos.x = laser[i].pos.x + 50;
                               isbreak = true;
                               laser[i].life -= enemy_normal[i].damage;
                               if (laser[i].life <= 0) {
                                   map[5 * j + i] = false;
                                   isbreak = false;
                                   //for (int t = 0; t < 10; t++) {

                                   //}
                               }
                           }
                           else if (j == 1 && enemy_normal[i].pos.x - 50 == machine[i].pos.x) {
                               enemy_normal[i].pos.x = machine[i].pos.x + 50;
                               isbreak = true;
                               machine[i].life -= enemy_normal[i].damage;
                               if (machine[i].life <= 0) {
                                   map[5 * j + i] = false;
                                   isbreak = false;
                                   for (int t = 0; t < 10; t++) {
                                       machinegun_wea[10 * i + t].enable = false;
                                   }
                               }
                           }
                           else if (j == 2 && enemy_normal[i].pos.x - 50 == Cannon[i].pos.x) {
                               enemy_normal[i].pos.x = Cannon[i].pos.x + 50;
                               isbreak = true;
                               Cannon[i].life -= enemy_normal[i].damage;
                               if (Cannon[i].life <= 0) {
                                   map[5 * j + i] = false;
                                   isbreak = false;
                                   cannon_wea[i].enable = false;
                               }
                           }

                       }
                       if (map[5 * j + i]) {
                           if (j == 0 && enemy_mid[i].pos.x - 50 == laser[i].pos.x) {
                               enemy_mid[i].pos.x = laser[i].pos.x + 50;
                               isbreak2 = true;
                               laser[i].life -= enemy_mid[i].damage;
                               if (laser[i].life <= 0) {
                                   map[5 * j + i] = false;
                                   isbreak2 = false;
                                   //for (int t = 0; t < 10; t++) {

                                   //}
                               }
                           }
                           else if (j == 1 && enemy_mid[i].pos.x - 50 == machine[i].pos.x) {
                               enemy_mid[i].pos.x = machine[i].pos.x + 50;
                               isbreak2 = true;
                               machine[i].life -= enemy_mid[i].damage;
                               if (machine[i].life <= 0) {
                                   map[5 * j + i] = false;
                                   isbreak2 = false;
                                   for (int t = 0; t < 10; t++) {
                                       machinegun_wea[10 * i + t].enable = false;
                                   }
                               }
                           }
                           else if (j == 2 && enemy_mid[i].pos.x - 50 == Cannon[i].pos.x) {
                               enemy_mid[i].pos.x = Cannon[i].pos.x + 50;
                               isbreak2 = true;
                               Cannon[i].life -= enemy_mid[i].damage;
                               if (Cannon[i].life <= 0) {
                                   map[5 * j + i] = false;
                                   isbreak2 = false;
                                   cannon_wea[i].enable = false;
                               }
                           }

                       }

                   }
                   if (!isbreak) enemy_normal[i].pos.x -= 2;
                   if (!isbreak2 && system_counter >= 400) enemy_mid[i].pos.x -= 2;
                   if (enemy_normal[i].pos.x <= 160) {
                       game = false;

                   }
                   if (enemy_mid[i].pos.x <= 160) {
                       game = false;

                   }


                   //if (layer != -1) {
                   //    if (layer == 0  && enemy_normal[i].pos.x - 50 <= laser[i].pos.x) {
                   //        enemy_normal[i].pos.x = laser[i].pos.x;
                   //    }    
                   //    else if (layer == 1 &&  enemy_normal[i].pos.x - 50 <= machine[i].pos.x) {
                   //        enemy_normal[i].pos.x = machine[i].pos.x +50;
                   //    }
                   //    else if (layer == 2 &&  enemy_normal[i].pos.x - 50 <= Cannon[i].pos.x) {
                   //        enemy_normal[i].pos.x = Cannon[i].pos.x + 50;
                   //    }
                   //    /*else if (layer == 3 &&  enemy_normal[i].pos.x  <= Landmine[i].pos.x) {
                   //        enemy_normal[i].pos.x = Landmine[i].pos.x;
                   //    }
                   //    else if (layer == 4 &&  enemy_normal[i].pos.x  <= Bomb[i].pos.x) {
                   //        enemy_normal[i].pos.x = Bomb[i].pos.x;
                   //    }*/
                   //    else {
                   //        enemy_normal[i].pos.x -= 2;
                   //        
                   //    }
                   //}
                   //else enemy_normal[i].pos.x -= 2;

               }
               this->label2->Location = System::Drawing::Point(enemy_normal[0].pos.x - 31, 114);
               this->label3->Location = System::Drawing::Point(enemy_normal[1].pos.x - 31, 195);
               this->label4->Location = System::Drawing::Point(enemy_normal[2].pos.x - 31, 270);
               this->label5->Location = System::Drawing::Point(enemy_normal[3].pos.x - 31, 340);
               this->label6->Location = System::Drawing::Point(enemy_normal[4].pos.x - 31, 413);
               this->label8->Location = System::Drawing::Point(enemy_mid[0].pos.x - 31, 114);
               this->label9->Location = System::Drawing::Point(enemy_mid[1].pos.x - 31, 195);
               this->label10->Location = System::Drawing::Point(enemy_mid[2].pos.x - 31, 270);
               this->label11->Location = System::Drawing::Point(enemy_mid[3].pos.x - 31, 340);
               this->label12->Location = System::Drawing::Point(enemy_mid[4].pos.x - 31, 413);
           }

           void collision() {
               for (int i = 0; i < 5; i++) {
                   //machine gun 
                   for (int j = 0; j < 10; j++) {
                       dis = sqrt((machinegun_wea[10 * i + j].pos.x - enemy_normal[i].pos.x) * (machinegun_wea[10 * i + j].pos.x - enemy_normal[i].pos.x) + (machinegun_wea[10 * i + j].pos.y - enemy_normal[i].pos.y) * (machinegun_wea[10 * i + j].pos.y - enemy_normal[i].pos.y));
                       dis2 = sqrt((machinegun_wea[10 * i + j].pos.x - enemy_mid[i].pos.x) * (machinegun_wea[10 * i + j].pos.x - enemy_mid[i].pos.x) + (machinegun_wea[10 * i + j].pos.y - enemy_mid[i].pos.y) * (machinegun_wea[10 * i + j].pos.y - enemy_mid[i].pos.y));
                       if (dis <= 20 && machinegun_wea[10 * i + j].enable) {
                           enemy_normal[i].life -= machinegun_wea[10 * i + j].damage;
                           machinegun_wea[10 * i + j].pos.x = machine[i].pos.x;
                           if (enemy_normal[i].life <= 0) {
                               //enemy_normal[i].enable = false;
                               enemy_normal[i].pos.x = 850;
                               enemy_normal[i].life = initial_enemy_life;
                               killed++;
                               coin += 20;
                           }
                       }
                       if (dis2 <= 20 && machinegun_wea[10 * i + j].enable) {
                           enemy_mid[i].life -= machinegun_wea[10 * i + j].damage;
                           machinegun_wea[10 * i + j].pos.x = machine[i].pos.x;
                           if (enemy_mid[i].life <= 0) {
                               //enemy_normal[i].enable = false;
                               enemy_mid[i].pos.x = 850;
                               enemy_mid[i].life = initial_enemy2_life;
                               killed++;
                               coin += 30;
                           }
                       }
                   }

                   // cannon
                   dis = sqrt((cannon_wea[i].pos.x - enemy_normal[i].pos.x) * (cannon_wea[i].pos.x - enemy_normal[i].pos.x) + (cannon_wea[i].pos.y - enemy_normal[i].pos.y) * (cannon_wea[i].pos.y - enemy_normal[i].pos.y));
                   dis2 = sqrt((cannon_wea[i].pos.x - enemy_mid[i].pos.x) * (cannon_wea[i].pos.x - enemy_mid[i].pos.x) + (cannon_wea[i].pos.y - enemy_mid[i].pos.y) * (cannon_wea[i].pos.y - enemy_mid[i].pos.y));
                   if (dis <= 20 && cannon_wea[i].enable) {
                       enemy_normal[i].life -= cannon_wea[i].damage;
                       cannon_wea[i].pos.x = Cannon[i].pos.x;
                       if (enemy_normal[i].life <= 0) {
                           //enemy_normal[i].enable = false;
                           enemy_normal[i].pos.x = 850;
                           enemy_normal[i].life = initial_enemy_life;
                           killed++;
                           coin += 20;
                       }
                   }
                   if (dis2 <= 20 && cannon_wea[i].enable) {
                       enemy_mid[i].life -= cannon_wea[i].damage;
                       cannon_wea[i].pos.x = Cannon[i].pos.x;
                       if (enemy_mid[i].life <= 0) {
                           //enemy_normal[i].enable = false;
                           enemy_mid[i].pos.x = 850;
                           enemy_mid[i].life = initial_enemy2_life;
                           killed++;
                           coin += 30;
                       }
                   }

                   // landmind
                   dis = sqrt((Landmine[i].pos.x - enemy_normal[i].pos.x) * (Landmine[i].pos.x - enemy_normal[i].pos.x) + (Landmine[i].pos.y - enemy_normal[i].pos.y) * (Landmine[i].pos.y - enemy_normal[i].pos.y));
                   dis2 = sqrt((Landmine[i].pos.x - enemy_mid[i].pos.x) * (Landmine[i].pos.x - enemy_mid[i].pos.x) + (Landmine[i].pos.y - enemy_mid[i].pos.y) * (Landmine[i].pos.y - enemy_mid[i].pos.y));
                   if (dis <= 30 && Landmine[i].enable) {
                       enemy_normal[i].life -= Landmine[i].damage;
                       map[15 + i] = false;
                       Landmine[i].enable = false;
                       if (enemy_normal[i].life <= 0) {
                           //enemy_normal[i].enable = false;
                           enemy_normal[i].pos.x = 850;
                           enemy_normal[i].life = initial_enemy_life;
                           killed++;
                           coin += 20;
                       }
                   }
                   if (dis2 <= 30 && Landmine[i].enable) {
                       enemy_mid[i].life -= Landmine[i].damage;
                       map[15 + i] = false;
                       Landmine[i].enable = false;
                       if (enemy_mid[i].life <= 0) {
                           //enemy_normal[i].enable = false;
                           enemy_mid[i].pos.x = 850;
                           enemy_mid[i].life = initial_enemy2_life;
                           killed++;
                           coin += 30;
                       }
                   }

                   // bomb
                   if (system_counter - Bomb[i].now_time >= 30) {
                       dis = sqrt((Bomb[i].pos.x - enemy_normal[i].pos.x) * (Bomb[i].pos.x - enemy_normal[i].pos.x) + (Bomb[i].pos.y - enemy_normal[i].pos.y) * (Bomb[i].pos.y - enemy_normal[i].pos.y));
                       dis2 = sqrt((Bomb[i].pos.x - enemy_mid[i].pos.x) * (Bomb[i].pos.x - enemy_mid[i].pos.x) + (Bomb[i].pos.y - enemy_mid[i].pos.y) * (Bomb[i].pos.y - enemy_mid[i].pos.y));
                       if (dis <= 50 && Bomb[i].enable) {
                           enemy_normal[i].life -= Bomb[i].damage;
                           if (enemy_normal[i].life <= 0) {
                               //enemy_normal[i].enable = false;
                               enemy_normal[i].pos.x = 850;
                               enemy_normal[i].life = initial_enemy_life;
                               killed++;
                               coin += 20;
                           }
                       }
                       if (dis2 <= 50 && Bomb[i].enable) {
                           enemy_mid[i].life -= Bomb[i].damage;
                           if (enemy_mid[i].life <= 0) {
                               //enemy_normal[i].enable = false;
                               enemy_mid[i].pos.x = 850;
                               enemy_mid[i].life = initial_enemy2_life;
                               killed++;
                               coin += 30;
                           }
                       }
                       map[20 + i] = false;
                       Bomb[i].enable = false;
                   }
               }
           }

           void initialize() {
               // gun
               for (int i = 0; i < 5; i++) {
                   // radius
                   laser[i].radius = 20;
                   machine[i].radius = 20;
                   Cannon[i].radius = 20;
                   Landmine[i].radius = 15;
                   Bomb[i].radius = 20;
                   // position
                   laser[i].pos.x = 184;
                   machine[i].pos.x = 280;
                   Cannon[i].pos.x = 360;
                   Landmine[i].pos.x = 458;
                   Bomb[i].pos.x = 522;
                   if (i == 0) {
                       laser[i].pos.y = 44;
                       machine[i].pos.y = 44;
                       Cannon[i].pos.y = 44;
                       Landmine[i].pos.y = 44;
                       Bomb[i].pos.y = 44;
                   }
                   else if (i == 1) {
                       laser[i].pos.y = 125;
                       machine[i].pos.y = 125;
                       Cannon[i].pos.y = 125;
                       Landmine[i].pos.y = 125;
                       Bomb[i].pos.y = 125;
                   }
                   else if (i == 2) {
                       laser[i].pos.y = 200;
                       machine[i].pos.y = 200;
                       Cannon[i].pos.y = 200;
                       Landmine[i].pos.y = 200;
                       Bomb[i].pos.y = 200;
                   }
                   else if (i == 3) {
                       laser[i].pos.y = 270;
                       machine[i].pos.y = 270;
                       Cannon[i].pos.y = 270;
                       Landmine[i].pos.y = 270;
                       Bomb[i].pos.y = 270;
                   }
                   else {
                       laser[i].pos.y = 343;
                       machine[i].pos.y = 343;
                       Cannon[i].pos.y = 343;
                       Landmine[i].pos.y = 343;
                       Bomb[i].pos.y = 343;
                   }
                   // life
                   laser[i].life =4 * 12;
                   machine[i].life =6 * 12;
                   Cannon[i].life = 8 * 12;
                   // damage
                   laser[i].damage = 5;
                   machine[i].damage = 2;
                   Cannon[i].damage = 8;
                   Landmine[i].damage = 50;
                   Bomb[i].damage = 100;
                   // shoot_v
                   laser[i].shoot_v = 5;
                   machine[i].shoot_v = 20;
                   Cannon[i].shoot_v = 50;
               }

               // weapon
               for (int i = 0; i < 5; i++) {
                   cannon_wea[i].radius = 20;
                   lasergun_wea[i].pos.x = 184;
                   cannon_wea[i].pos.x = 350;
                   cannon_wea[i].damage = 10;
                   lasergun_wea[i].damage = 4;
               }
               for (int i = 0; i < 5 * 10; i++) {
                   machinegun_wea[i].radius = 5;
                   machinegun_wea[i].pos.x = 280;
                   machinegun_wea[i].pos.y = machine[i / 10].pos.y;
                   machinegun_wea[i].damage = 2;
               }



               // enemy
               for (int i = 0; i < 5; i++) {
                   enemy_normal[i].damage = 1;
                   enemy_normal[i].life = initial_enemy_life;
                   enemy_normal[i].radius = 20;
                   enemy_normal[i].pos.x = 850;
                   enemy_mid[i].damage = 3;
                   enemy_mid[i].life = initial_enemy2_life;
                   enemy_mid[i].radius = 20;
                   enemy_mid[i].pos.x = 850;
                   if (i == 0) {
                       enemy_normal[i].pos.y = 44;
                       enemy_mid[i].pos.y = 44;
                   }
                   else if (i == 1) {
                       enemy_normal[i].pos.y = 125;
                       enemy_mid[i].pos.y = 125;
                   }
                   else if (i == 2) {
                       enemy_normal[i].pos.y = 200;
                       enemy_mid[i].pos.y = 200;
                   }
                   else if (i == 3) {
                       enemy_normal[i].pos.y = 270;
                       enemy_mid[i].pos.y = 270;
                   }
                   else {
                       enemy_normal[i].pos.y = 343;
                       enemy_mid[i].pos.y = 343;
                   }
               }
           }

           void button_hidden() {
               if (this->button7->Visible == true) {
                   this->button7->Visible = false;
               }
               if (this->button8->Visible == true) {
                   this->button8->Visible = false;
               }
               if (this->button9->Visible == true) {
                   this->button9->Visible = false;
               }
               if (this->button10->Visible == true) {
                   this->button10->Visible = false;
               }
               if (this->button11->Visible == true) {
                   this->button11->Visible = false;
               }
               if (this->button12->Visible == true) {
                   this->button12->Visible = false;
               }
               if (this->button13->Visible == true) {
                   this->button13->Visible = false;
               }
               if (this->button14->Visible == true) {
                   this->button14->Visible = false;
               }
               if (this->button15->Visible == true) {
                   this->button15->Visible = false;
               }
               if (this->button16->Visible == true) {
                   this->button16->Visible = false;
               }
               if (this->button17->Visible == true) {
                   this->button17->Visible = false;
               }
               if (this->button18->Visible == true) {
                   this->button18->Visible = false;
               }
               if (this->button19->Visible == true) {
                   this->button19->Visible = false;
               }
               if (this->button20->Visible == true) {
                   this->button20->Visible = false;
               }
               if (this->button21->Visible == true) {
                   this->button21->Visible = false;
               }
               if (this->button22->Visible == true) {
                   this->button22->Visible = false;
               }
               if (this->button23->Visible == true) {
                   this->button23->Visible = false;
               }
               if (this->button24->Visible == true) {
                   this->button24->Visible = false;
               }
               if (this->button25->Visible == true) {
                   this->button25->Visible = false;
               }
               if (this->button26->Visible == true) {
                   this->button26->Visible = false;
               }
               if (this->button27->Visible == true) {
                   this->button27->Visible = false;
               }
               if (this->button28->Visible == true) {
                   this->button28->Visible = false;
               }
               if (this->button29->Visible == true) {
                   this->button29->Visible = false;
               }
               if (this->button30->Visible == true) {
                   this->button30->Visible = false;
               }
               if (this->button31->Visible == true) {
                   this->button31->Visible = false;
               }
           }

           void button_display_laser() {
               if (map[0] == false) {
                   this->button7->Visible = true;
               }
               if (map[1] == false) {
                   this->button8->Visible = true;
               }
               if (map[2] == false) {
                   this->button9->Visible = true;
               }
               if (map[3] == false) {
                   this->button10->Visible = true;
               }
               if (map[4] == false) {
                   this->button11->Visible = true;
               }
           }

           void button_display_machine() {
               if (map[5] == false) {
                   this->button12->Visible = true;
               }
               if (map[6] == false) {
                   this->button13->Visible = true;
               }
               if (map[7] == false) {
                   this->button14->Visible = true;
               }
               if (map[8] == false) {
                   this->button15->Visible = true;
               }
               if (map[9] == false) {
                   this->button16->Visible = true;
               }
           }

           void button_display_cannon() {
               if (map[10] == false) {
                   this->button17->Visible = true;
               }
               if (map[11] == false) {
                   this->button18->Visible = true;
               }
               if (map[12] == false) {
                   this->button19->Visible = true;
               }
               if (map[13] == false) {
                   this->button20->Visible = true;
               }
               if (map[14] == false) {
                   this->button21->Visible = true;
               }
           }

           void button_display_landmine() {
               if (map[15] == false) {
                   this->button22->Visible = true;
               }
               if (map[16] == false) {
                   this->button23->Visible = true;
               }
               if (map[17] == false) {
                   this->button24->Visible = true;
               }
               if (map[18] == false) {
                   this->button25->Visible = true;
               }
               if (map[19] == false) {
                   this->button26->Visible = true;
               }
           }

           void button_display_bomb() {
               if (map[20] == false) {
                   this->button27->Visible = true;
               }
               if (map[21] == false) {
                   this->button28->Visible = true;
               }
               if (map[22] == false) {
                   this->button29->Visible = true;
               }
               if (map[23] == false) {
                   this->button30->Visible = true;
               }
               if (map[24] == false) {
                   this->button31->Visible = true;
               }
           }


#pragma endregion
    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
        // main

        if (!game) {
            gameoverform^ gameover = gcnew gameoverform();

            // 顯示secondform
            gameover->Show();
            this->Close();
            player->Stop();
        }
        if (system_counter == 0) {
            initialize();


            // 播放音樂
            
        }
        if (system_counter%940 == 0) { player->Play(); }
        if (killed >= 40) {
            nextform3^ nextform = gcnew nextform3();

            // 顯示secondform
            nextform->Show();
            this->Close();
            player->Stop();
        }

        Motion();
        //plot_HMI();
        collision();
        text_displayer();
        pictureBox1->Invalidate();
        system_counter++;
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // back
        this->Close();
        player->Stop();
    }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // laser gun
        if (coin >= 20) {
            coin -= 20;
            button_display_laser();
            for (int i = 0; i < 5; i++) {
                laser[i].life = 4 * 12;
            }
        }
    }
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // machine gun
        if (coin >= 50) {
            coin -= 50;
            button_display_machine();
            for (int i = 0; i < 5; i++) {
                machine[i].life = 6 * 12;
            }
        }
    }
    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { // cannon
        if (coin >= 40) {
            coin -= 40;
            button_display_cannon();
            for (int i = 0; i < 5; i++) {
                Cannon[i].life = 8 * 12;
            }
        }
    }
    private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { // landmine
        if (coin >= 15) {
            coin -= 15;
            button_display_landmine();
        }
    }
    private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) { // bomb
        if (coin >= 35) {
            coin -= 35;
            button_display_bomb();
        }
    }
    private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) { // map[0]
        map[0] = true;
        button_hidden();
        this->lasergun_wea[0].now_time = system_counter;
    }
    private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) { // map[1]
        map[1] = true;
        button_hidden();
        this->lasergun_wea[1].now_time = system_counter;
    }
    private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) { // map[2]
        map[2] = true;
        button_hidden();
        this->lasergun_wea[2].now_time = system_counter;
    }
    private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) { // map[3]
        map[3] = true;
        button_hidden();
        this->lasergun_wea[3].now_time = system_counter;
    }
    private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) { // map[4]
        map[4] = true;
        button_hidden();
        this->lasergun_wea[4].now_time = system_counter;
    }
    private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) { // map[5]
        map[5] = true;
        button_hidden();
        for (int i = 0; i < 10; i++) {
            this->machinegun_wea[0 + i].now_time = system_counter + i * 10;
            this->machinegun_wea[0 + i].enable = true;
        }
    }
    private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) { // map[6]
        map[6] = true;
        button_hidden();
        for (int i = 0; i < 10; i++) {
            this->machinegun_wea[10 + i].now_time = system_counter + i * 10;
            this->machinegun_wea[10 + i].enable = true;
        }
    }
    private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) { // map[7]
        map[7] = true;
        button_hidden();
        for (int i = 0; i < 10; i++) {
            this->machinegun_wea[20 + i].now_time = system_counter + i * 10;
            this->machinegun_wea[20 + i].enable = true;
        }
    }
    private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) { // map[8]
        map[8] = true;
        button_hidden();
        for (int i = 0; i < 10; i++) {
            this->machinegun_wea[30 + i].now_time = system_counter + i * 10;
            this->machinegun_wea[30 + i].enable = true;
        }
    }
    private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) { // map[9]
        map[9] = true;
        button_hidden();
        for (int i = 0; i < 10; i++) {
            this->machinegun_wea[40 + i].now_time = system_counter + i * 10;
            this->machinegun_wea[40 + i].enable = true;
        }
    }
    private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) { // map[10]
        map[10] = true;
        button_hidden();
        this->cannon_wea[0].enable = 1;
    }
    private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) { // map[11]
        map[11] = true;
        button_hidden();
        this->cannon_wea[1].enable = 1;
    }
    private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) { // map[12]
        map[12] = true;
        button_hidden();
        this->cannon_wea[2].enable = 1;
    }
    private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) { // map[13]
        map[13] = true;
        button_hidden();
        this->cannon_wea[3].enable = 1;
    }
    private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) { // map[14]
        map[14] = true;
        button_hidden();
        this->cannon_wea[4].enable = 1;
    }
    private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) { // map[15]
        map[15] = true;
        button_hidden();
        this->Landmine[0].enable = true;
    }
    private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) { // map[16]
        map[16] = true;
        button_hidden();
        this->Landmine[1].enable = true;
    }
    private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) { // map[17]
        map[17] = true;
        button_hidden();
        this->Landmine[2].enable = true;
    }
    private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) { // map[18]
        map[18] = true;
        button_hidden();
        this->Landmine[3].enable = true;
    }
    private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) { // map[19]
        map[19] = true;
        button_hidden();
        this->Landmine[4].enable = true;
    }
    private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) { // map[20]
        map[20] = true;
        button_hidden();
        this->Bomb[0].enable = true;
        this->Bomb[0].now_time = system_counter;
    }
    private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) { // map[21]
        map[21] = true;
        button_hidden();
        this->Bomb[1].enable = true;
        this->Bomb[1].now_time = system_counter;
    }
    private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) { // map[22]
        map[22] = true;
        button_hidden();
        this->Bomb[2].enable = true;
        this->Bomb[2].now_time = system_counter;
    }
    private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) { // map[23]
        map[23] = true;
        button_hidden();
        this->Bomb[3].enable = true;
        this->Bomb[3].now_time = system_counter;
    }
    private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) { // map[24]
        map[24] = true;
        button_hidden();
        this->Bomb[4].enable = true;
        this->Bomb[4].now_time = system_counter;
    }
    };
}