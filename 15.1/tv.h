#ifndef tv_H_
#define tv_H_
#include<iostream>
using std::cout;
using std::endl;

class Remote;//ǰ������

class Tv {
private:
	int state;			//on or off
	int volume;			//assumed to be digitized
	int maxchannel;		//maximum number of channels
	int channel;		//current channel setting
	int mode;			//broadcast or cable
	int input;			//TV or DVD
public:
	friend class Remote;//��Ԫ������������λ���޹ؽ�Ҫ
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125) :state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV){}
	~Tv() {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
	void set_rmode(Remote& r);//��TV�������һ����Remote�³�Ա�����л��ķ���
};

class Remote {
private:
	friend class Tv;
	enum { NORMAL, INTERACT };//��Remote�������һ��״̬����,����ң�������ڳ���ģʽ���ǻ���ģʽ
	int mode;
	int fmode;
public:
	Remote(int m = Tv::TV, int f = NORMAL) :mode(m), fmode(f){}
	bool volup(Tv& t) { return t.volup(); }
	bool voldown(Tv& t) { return t.voldown(); }
	void onoff(Tv& t) { t.onoff(); }
	void chanup(Tv& t) { t.chanup(); }
	void chandown(Tv& t) { t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }
	void mode_show() const { cout << "Remote mode is " << (fmode == NORMAL ? "NORMAL" : "INTERACT") << endl; }//��Remote�����һ����ʾģʽ�ķ���
};

inline void Tv::set_rmode(Remote& r)
{
	if (ison())
		r.fmode = (r.fmode == Remote::INTERACT ? Remote::NORMAL : Remote::INTERACT);
	else
		cout << "TV is off!\n";
}


#endif // !tv_H_

