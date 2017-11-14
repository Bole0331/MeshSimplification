
struct point{

public:
	double x, y, z;
	point(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {}
	double length() const;
	bool operator == (const point & cmp) const;
	bool operator < (const point & cmp) const;
	double operator[] (int t) const;
	double operator * (const point & cmp) const ;
	const point normalize() const;
	
	friend const point operator * (const point & _p, double a);
	friend const point operator / (const point & _p, double a);
	friend const point operator + (const point & _p, const point & _q);
};
