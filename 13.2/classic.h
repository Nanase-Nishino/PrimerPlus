#ifndef classic_H_
#define classic_H_

class Cd {  //represents a CD disk
private:
	char* performers;
	char* label;
	int selections;				//number of selections
	double playtime;			//playing time in minutes
public:
	Cd();
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	virtual ~Cd();
	virtual void Report() const;		//reports all CD data
	Cd& operator=(const Cd& d);
};

class Classic : public Cd {
private:
	char* major;
public:
	Classic();
	Classic(const char* _major, const char* s1, const char* s2, int n, double x);
	Classic(const char* _major, const Cd& cd);
	virtual ~Classic();
	virtual void Report() const;
	Classic& operator=(const Classic& d);
};

#endif // !classic_H_

