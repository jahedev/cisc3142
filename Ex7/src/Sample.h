//
// Created by Jahed Hossain on 11/9/22.
//

#ifndef SOURCE_H
#define SOURCE_H

class Sample
{
private:
    int x;
    double y;
public:
    // unspecified values will bet set to use default constructor
    // so by default, x and y = 0.
    Sample(): x(0), y(0.0) {}

    Sample(const int &val_x): x(val_x) {}
    Sample(const int &x, const int &y): x(x), y(y) {}
    Sample(const int &x, const double &y): x(x), y(y) {}

    friend std::ostream &printValues(std::ostream &os, Sample& sample)
    {
        os << std::to_string(sample.x) << " " << std::to_string(sample.y);
        return os;
    }
    
};

std::ostream &printValues(std::ostream&, Sample&);

#endif //SOURCE_H
