#ifndef THREEVECTOR_HPP
#define THREEVECTOR_HPP


class ThreeVector {
  public:
	//Constructors
	ThreeVector(){ x_=0; y_=0; z_=0; len_=0;}
	ThreeVector(const ThreeVector& other);
	ThreeVector(const double x, const double y, const double z);

	//Member functions
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	double getX() const;
	double getY() const;
	double getZ() const;
	double length() const;
	

 private:
	//Member variables
	double x_;
	double y_;
	double z_;
	double len_;

	//Private member functions
	void compute_length();

};

#endif //THREEVECTOR_HPP
