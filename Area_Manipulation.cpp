#include<iostream>
using namespace std;

//Making class name Rectangle.
class Rectangle{
    private:
    float length;
    float width;

    public:

//default constructer.
    Rectangle()
    {

    }

//Parameterized constructer.
    Rectangle(float length_input,float width_input)
    {
        this->length=length_input;
        this->width=width_input;
    }

//setting the lenth.
    void setlength(float length_input)
    {
        this->length=length_input;
    }

//setting the width.
    void setwidth(float width_input)
    {
        this->width=width_input;
    }

//Getters.

    float getwidth()
    {
        return width;
    }

    float getlength()
    {
        return length;
    }
    
//calculating the parameter of the reactangle.

    float parameter()
    {
        float parameter=2*(length+width);
        return parameter;
    }

//calculating the Area of the Rectangle.

    float area()
    {
        float area=(length*width);
        return area;
    }

//Function to display the length and width of the Rectangle.

    void show()
    {
        cout<<endl<<"LENGTH OF THE RECTANGLE IS : "<<length<<endl;
        cout<<"WIDTH  OF THE RECTANGLE IS : "<<width<<endl;
    }

//Comparing the Area of two REctangles.
   int same_area(Rectangle R)
    {
if(area()==R.area())
{
    return 1;
}
else{
    return 0;
}

    }
};//end of the class.

//Main FUnction
int main()
{
//specifying the values for rectangle -01 
Rectangle first_rectangle(5,2.5);
cout<<endl;
//calling show function to display length and width.
first_rectangle.show();
cout<<endl;
cout<<"PARAMETER OF THE FIRST RECTANGLE IS : "<<first_rectangle.parameter()<<endl;
cout<<"AREA OF THE FIRST RECTANGLE IS : "<<first_rectangle.area()<<endl<<endl;

//specifying the values for rectangle -02
Rectangle second_rectangle(5,18.9);
//calling show function to display length and width.
second_rectangle.show();
cout<<endl;
cout<<"PARAMETER OF THE SECOND RECTANGLE IS : "<<second_rectangle.parameter()<<endl;
cout<<"AREA OF THE SECOND RECTANGLE IS : "<<second_rectangle.area()<<endl<<endl;

//calling same area function.
if(first_rectangle.same_area(second_rectangle))
{
    cout<<"\n\tBOTH RECTANGLES HAVE SAME AREA\n";
}
else{
    cout<<"\t BOTH RECTANGLES HAVE DIFFERENT AREA\n\n";
}

///
//specifying the values for rectangle -01 
first_rectangle.setlength(15);
first_rectangle.setwidth(6.3);

cout<<endl;
//calling show function to display length and width.
first_rectangle.show();
cout<<endl;
cout<<"PARAMETER OF THE FIRST RECTANGLE IS : "<<first_rectangle.parameter()<<endl;
cout<<"AREA OF THE FIRST RECTANGLE IS : "<<first_rectangle.area()<<endl<<endl;

//specifying the values for rectangle -02
second_rectangle.setlength(5);
second_rectangle.setwidth(18.9);
//calling show function to display length and width.
second_rectangle.show();
cout<<endl;
cout<<"PARAMETER OF THE SECOND RECTANGLE IS : "<<second_rectangle.parameter()<<endl;
cout<<"AREA OF THE SECOND RECTANGLE IS : "<<second_rectangle.area()<<endl<<endl;

//calling same area function.
if(first_rectangle.same_area(second_rectangle))
{
    cout<<"\tBOTH RECTANGLES HAVE SAME AREA\n\n";
}
else{
    cout<<"\t BOTH RECTANGLES HAVE DIFFERENT AREA\n\n";
}

return 0;
}