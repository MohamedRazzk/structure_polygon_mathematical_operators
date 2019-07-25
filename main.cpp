#include <iostream>
#include <cctype>
#include <string>
#include<sstream>
#include<stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#define infinty 9999999

using namespace std ;

string intostring (int number) {ostringstream oss ;oss<<number;return oss.str();} // into string re-cus-function

int Number_Polygons (string input , int input_length) //function to get polygons number
{
    int polygon_numbers = 0 ;

    for (int i=0 ; i <= input_length ; i++ )
    {
        if ( input [i]== ';')
        {
            polygon_numbers = polygon_numbers +1 ;
        }
    }
    return  polygon_numbers+1 ;
}

int Total_Number_Points (string input , int input_length) //function to get total number of points
{
    int number_point = 0 ;
    for (int i = 0 ; i <= input_length  ; i++ )
    {
        if (input[i]=='(')
        {
            number_point = number_point  + 1 ;
        }
    }
    return  number_point ;
}

double Minimum_X (string points , int number)       //function to get min x
{
    int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;

    for (int i =0 ;  i<= points.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (points[i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
        if (points[i]== ','){counter2=counter2+1;  col[counter2]=i ;}
        if (points[i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
    }

    double min=atof(points.substr(arc[1]+1,col[colrep]-arc[1]-1).c_str());
    for (int i = 1 ; i <=number ; i++){

        if (min > atof(points.substr(arc[i]+1,col[colrep]-arc[i]-1).c_str())){

            min = atof(points.substr(arc[i]+1,col[colrep]-arc[i]-1).c_str());
        }

        colrep +=2 ;
    }
    return min ;
}

double Maximum_X (string points , int number)       //function to get max x
{
    int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;

    for (int i =0 ;  i<= points.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (points[i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
        if (points[i]== ','){counter2=counter2+1;  col[counter2]=i ;}
        if (points[i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
    }
    float max=atof(points.substr(arc[1]+1,col[colrep]-arc[1]-1).c_str());
    ;
    for (int i = 1 ; i <=number ; i++){
        if (max < atof(points.substr(arc[i]+1,col[colrep]-arc[i]-1).c_str())){

            max = atof(points.substr(arc[i]+1,col[colrep]-arc[i]-1).c_str());
        }

        colrep +=2 ;
    }
    return max ;
}

double Maximum_Y (string points , int number)       //function to get max y
{
    int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;

    for (int i =0 ;  i<= points.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (points[i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
        if (points[i]== ','){counter2=counter2+1;  col[counter2]=i ;}
        if (points[i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
    }
    float max=atof(points.substr(col[colrep]+1,inarc[1]-col[colrep]-1).c_str());
    ;
    for (int i = 1 ; i <=number ; i++){
        if (max < atof(points.substr(col[colrep]+1,inarc[i]-col[colrep]-1).c_str())){

            max = atof(points.substr(col[colrep]+1,inarc[i]-col[colrep]-1).c_str());
        }

        colrep +=2 ;
    }
    return max ;
}

double Minimum_Y (string points , int number)       //function to get min y
{
    int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;

    for (int i =0 ;  i<= points.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (points[i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
        if (points[i]== ','){counter2=counter2+1;  col[counter2]=i ;}
        if (points[i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
    }
    double min=atof(points.substr(col[colrep]+1,inarc[1]-col[colrep]-1).c_str());
    ;
    for (int i = 1 ; i <=number ; i++){
        if (min > atof(points.substr(col[colrep]+1,inarc[i]-col[colrep]-1).c_str())){

            min = atof(points.substr(col[colrep]+1,inarc[i]-col[colrep]-1).c_str());
        }

        colrep +=2 ;
    }
    return min ;
}

void Enclosing_Rectangle (string points , string input , int string_length) // function to get Enclosing Rectangle
{
    cout << "("<<  Minimum_X(points , Total_Number_Points(input , string_length)) <<"," << Minimum_Y(points , Total_Number_Points(input , string_length))<<")"<< ","
         << "("<<  Minimum_X(points , Total_Number_Points(input , string_length)) <<"," << Maximum_Y(points , Total_Number_Points(input , string_length))<<")"<< ","
         << "("<<  Maximum_X(points , Total_Number_Points(input , string_length)) <<"," << Maximum_Y(points , Total_Number_Points(input , string_length))<<")"<< ","
         << "("<<  Maximum_X(points , Total_Number_Points(input , string_length)) <<"," << Minimum_Y(points , Total_Number_Points(input , string_length))<<")";


}

int Redundant_points (string points , int number ) // function to number of redundant at polygon
{
    int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;

    for (int i =0 ;  i<= points.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (points[i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
        if (points[i]== ','){counter2=counter2+1;  col[counter2]=i ;}
        if (points[i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
    }
    float x[1000]; float y [1000]; float slope[1000];

    for (int i = 1 ; i <=number ; i++){

        x[i]=atof(points.substr(arc[i]+1,col[colrep]-arc[i]-1).c_str()) ;
        y[i]=atof(points.substr(col[colrep]+1,inarc[i]-col[colrep]-1).c_str())  ;

        colrep +=2 ;

    }

    float xr[1000]; float yr[1000];
    xr[1]=x[1]; yr[1]=y[1];
    //  int repeater = 2 ;
    int re =0;

    slope[1]=((y[1+1]-y[1])/(x[1+1]-x[1]));
    for (int i = 2 ; i<=number ; i++)
    {
        slope[i]=((y[i+1]-y[i])/(x[i+1]-x[i]));

        for (int p =2 ; p <=number ;p++){

            if (x[i-1]==x[i] && y[i-1]==y[i]) { re +=1 ; break; } // get redundant of dip point
            if(x[i+1]-x[i] !=0 && slope[i]==slope[i-1]) { re +=1 ;break; } // getting redundant point of slope
            if (x[i+1]-x[i]==0 && y[i+1]-y[i]!=0 && x[i]-x[i-1]==0 && y[i]-y[i-1]!=0 ){  re+=1;   ; break; }// get redundant of x-x =0

            // xr[repeater] = x[i];yr[repeater] =y[i];repeater +=1 ;

            break ;
        }}

    //for (int i=1 ;i<repeater ; i++) { cout << "X = " << xr[i] << endl;cout << "y = " << yr[i] << endl; }

    return re ;
}

void polygon_points_re (string points , int number ) //function to points of polygon without redundant
{

    int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;

    for (int i =0 ;  i<= points.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (points[i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
        if (points[i]== ','){counter2=counter2+1;  col[counter2]=i ;}
        if (points[i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
    }
    float x[1000]; float y [1000]; float slope[1000];

    for (int i = 1 ; i <=number ; i++){

        x[i]=atof(points.substr(arc[i]+1,col[colrep]-arc[i]-1).c_str()) ;
        y[i]=atof(points.substr(col[colrep]+1,inarc[i]-col[colrep]-1).c_str())  ;

        colrep +=2 ;

    }

    float xr[1000]; float yr[1000];
    xr[1]=x[1]; yr[1]=y[1];
    int repeater = 2 ;
    int re =0 ; int re2=0 ;
    slope[1]=((y[1+1]-y[1])/(x[1+1]-x[1]));

    for (int i = 2 ; i<=number ; i++)
    {
        slope[i]=((y[i+1]-y[i])/(x[i+1]-x[i]));

        for (int p =2 ; p <=number ;p++){

            if (x[i-1]==x[i] && y[i-1]==y[i]) { re +=1 ; break; } // get redundant of dip point
            if(x[i+1]-x[i] !=0 && slope[i]==slope[i-1]) { re +=1 ;break; } // getting redundant point of slope
            if (x[i+1]-x[i]==0 && y[i+1]-y[i]!=0 && x[i]-x[i-1]==0 && y[i]-y[i-1]!=0 ){  re+=1;   ; break; }// get redundant of x-x =0

            xr[repeater] = x[i];
            yr[repeater] =y[i];

            repeater +=1 ;

            break ;
        }}

    for (int i=1 ;i<repeater ; i++)
    {

        cout << "(" << xr[i] << "," << yr[i] <<")" ;
        if (i<repeater-1)
        { cout <<","; }
    }

}

void polygon_points_fn (string input , string p_operation)  //function to get number of polygon contain point
{


    int arcc[10]; int colc[10]; int inarcc[10]; int counter11=0;int counter22=0; int counter33 = 0; int colrepc = 1;

    for (int i =0 ;  i<= p_operation.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (p_operation[i]== '('){counter11=counter11+1;  arcc[counter11]=i ;}
        if (p_operation[i]== ','){counter22=counter22+1;  colc[counter22]=i ;}
        if (p_operation[i]== ')'){counter33=counter33+1;inarcc[counter33]=i ;}
    }
    float xc[10]; float yc [10];

    for (int i = 1 ; i <=1 ; i++){

        xc[i]=atof(p_operation.substr(arcc[i]+1,colc[colrepc]-arcc[i]-1).c_str()) ;
        yc[i]=atof(p_operation.substr(colc[colrepc]+1,inarcc[i]-colc[colrepc]-1).c_str())  ;
        // cout  << "the value of xc = "  << xc[i] << " " << "the value of yc " << yc[i] <<endl;
        colrepc +=2 ;
    }




    string  points = "" ;

    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}


    /*--------------------------------------------------------------------*/



    float x[500] ; float y[500];  bool checker = false ; bool checker1 = false   ;

    for ( int s=1 ;  s<=Number_Polygons(input,input.length()) ; s++) {

        int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;


        for (int i =0 ;  i<= polygon_points[s].length() ;i++ ) //getting place of that "(" and  ")" and ","
        {
            if (polygon_points[s][i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
            if (polygon_points[s][i]== ','){counter2=counter2+1;  col[counter2]=i ;}
            if (polygon_points[s][i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
        }

        for (int i = 1 ; i <=polygon_pn[s] ; i++){

            x[i]=atof(polygon_points[s].substr(arc[i]+1,col[colrep]-arc[i]-1).c_str()) ;
            y[i]=atof(polygon_points[s].substr(col[colrep]+1,inarc[i]-col[colrep]-1).c_str());

            if (x[i]==xc[1] && y[i]==yc[1])
            { if (checker == true ){cout << ","; } cout<<s ;  checker =true ; checker1= true; break ; }

            colrep +=2 ;

        }

    }
    if (checker1== false) {cout <<"none";}





}

void polygons_w_r (string &points , int number ) //function to get all polygons point without redundant
{
    string plw ="";
    int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;

    for (int i =0 ;  i<= points.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (points[i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
        if (points[i]== ','){counter2=counter2+1;  col[counter2]=i ;}
        if (points[i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
    }
    float x[1000]; float y [1000]; float slope[1000];

    for (int i = 1 ; i <=number ; i++){

        x[i]=atof(points.substr(arc[i]+1,col[colrep]-arc[i]-1).c_str()) ;
        y[i]=atof(points.substr(col[colrep]+1,inarc[i]-col[colrep]-1).c_str())  ;

        colrep +=2 ;

    }

    float xr[1000]; float yr[1000];
    xr[1]=x[1]; yr[1]=y[1];
    int repeater = 2 ;
    int re =0 ; int re2=0 ;
    slope[1]=((y[1+1]-y[1])/(x[1+1]-x[1]));



    for (int i = 2 ; i<=number ; i++)
    {
        slope[i]=((y[i+1]-y[i])/(x[i+1]-x[i]));

        for (int p =2 ; p <=number ;p++){

            if (x[i-1]==x[i] && y[i-1]==y[i]) { re +=1 ; break; } // get redundant of dip point
            if(x[i+1]-x[i] !=0 && slope[i]==slope[i-1]) { re +=1 ;break; } // getting redundant point of slope
            if (x[i+1]-x[i]==0 && y[i+1]-y[i]!=0 && x[i]-x[i-1]==0 && y[i]-y[i-1]!=0 ){  re+=1;   ; break; }// get redundant of x-x =0

            xr[repeater] = x[i];
            yr[repeater] =y[i];

            repeater +=1 ;

            break ;
        }}

    for (int i=1 ;i<repeater ; i++)
    {

        plw += "(" + intostring(xr[i]) + "," + intostring(yr[i]) +")" ;
        if (i<repeater-1)
        { plw +=","; }
    }
    // cout << plw << endl ;
    points = plw ;
}

void List_Polygons_Points_More (string input ,int p_operation) //function to get polygon more than p operation number
{
    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}
    bool checker= false ;
    for (int i=1 ; i <= Number_Polygons(input,string_length);i++)
    {

        if (polygon_pn[i] > p_operation)
        {
            checker = true ;

            cout << i  ;
            if(i<=Number_Polygons(input,string_length)&&polygon_pn[i+1] > p_operation)
            {cout << ",";}
        }



    }
    if (checker==false) {cout << "none";}

}

void List_Polygons_Points_less (string input ,int p_operation) //function to get polygon more than p operation number
{
    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}
    bool checker = false;
    for (int i=1 ; i <= Number_Polygons(input,string_length);i++)
    {

        if (polygon_pn[i] < p_operation)
        {
            cout << i  ;
            checker = true ;


        }
        if(i<=Number_Polygons(input,string_length)-1 && polygon_pn[i+1] < p_operation )
        {cout << ",";}
    }
    if (checker==false) {cout << "none";}


}

void List_Polygons_Points_Equal (string input ,int p_operation) //function to get polygon more than p operation number
{
    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */

    bool checker = false;

    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}

    for (int i=1 ; i <= Number_Polygons(input,string_length);i++)
    {

        if (polygon_pn[i] == p_operation)
        {
            checker = true ;
            cout << i  ;
            if(i<=Number_Polygons(input,string_length)-1 && polygon_pn[i+1] == p_operation )
            {cout << ",";}
        }

    }
    if (checker==false) {cout << "none";}


}

void List_Points_Polygons_More (string input ,int p_operation) //function to get polygon points more than p operation number
{
    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */

    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}

    bool checker = false ;

    for (int i=1 ; i <= Number_Polygons(input,string_length);i++)
    {

        if (polygon_pn[i] > p_operation)
        {
            checker = true ;
            cout << polygon_points[i]   ;
            if(i<=Number_Polygons(input,string_length)&&polygon_pn[i+1] > p_operation)
            {cout << ";";}
        }



    }

    if (checker==false){cout <<"none";}
}

void List_Points_Polygons_less (string input ,int p_operation) //function to get polygon points  more than p operation number
{
    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */
    bool  checker= false ;


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}

    for (int i=1 ; i <= Number_Polygons(input,string_length);i++)
    {

        if (polygon_pn[i] < p_operation)
        {
            checker = true;
            cout << polygon_points[i]  ;

        }
        if(i<=Number_Polygons(input,string_length)-1 && polygon_pn[i+1] < p_operation )
        {cout << ";";}
    }
    if (checker == false) {cout << "none";}
}

void List_Points_Polygons_Equal (string input ,int p_operation) //function to get polygon points  more than p operation number
{
    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */
    bool checker=false ;

    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}

    for (int i=1 ; i <= Number_Polygons(input,string_length);i++)
    {

        if (polygon_pn[i] == p_operation)
        {
            checker = true ;
            cout << polygon_points[i]  ;
            if(i<=Number_Polygons(input,string_length)-1 && polygon_pn[i+1] == p_operation )
            {cout << ";";}
        }

    }
    if (checker== false) {cout << "none" ;}
}

void polygon_perimeter (string points , int number )         //function to get perimeter
{

    int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;

    for (int i =0 ;  i<= points.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (points[i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
        if (points[i]== ','){counter2=counter2+1;  col[counter2]=i ;}
        if (points[i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
    }
    float x[1000]; float y [1000]; float slope[1000];

    for (int i = 1 ; i <=number ; i++){

        x[i]=atof(points.substr(arc[i]+1,col[colrep]-arc[i]-1).c_str()) ;
        y[i]=atof(points.substr(col[colrep]+1,inarc[i]-col[colrep]-1).c_str())  ;

        colrep +=2 ;

    }

    float xr[1000]; float yr[1000];
    xr[1]=x[1]; yr[1]=y[1];
    int repeater = 2 ;
    int re =0 ; int re2=0 ;
    slope[1]=((y[1+1]-y[1])/(x[1+1]-x[1]));

    for (int i = 2 ; i<=number ; i++)
    {
        slope[i]=((y[i+1]-y[i])/(x[i+1]-x[i]));

        for (int p =2 ; p <=number ;p++){

            if (x[i-1]==x[i] && y[i-1]==y[i]) { re +=1 ; break; } // get redundant of dip point
            if(x[i+1]-x[i] !=0 && slope[i]==slope[i-1]) { re +=1 ;break; } // getting redundant point of slope
            if (x[i+1]-x[i]==0 && y[i+1]-y[i]!=0 && x[i]-x[i-1]==0 && y[i]-y[i-1]!=0 ){  re+=1;   ; break; }// get redundant of x-x =0

            xr[repeater] = x[i];
            yr[repeater] =y[i];

            repeater +=1 ;

            break ;
        }}




    double per= sqrt(pow(xr[1]-xr[repeater-1],2)+pow(yr[1]-yr[repeater-1],2));
    for (int i=1 ;i<repeater-1 ; i++) // that loop calculate te perimeter form points
    {
        per +=  sqrt(pow(yr[i+1]-yr[i],2)+pow(xr[i+1]-xr[i],2));
    }
    cout <<per << endl ;

}

void List_Triangles (string input)                              //function to output triangles
{
    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */

    bool checker = false;

    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}

    for (int i=1 ; i <= Number_Polygons(input,string_length);i++)
    {

        if (polygon_pn[i] == 3)
        {
            checker = true ;
            cout << i  ;
            if(i<=Number_Polygons(input,string_length)-1 && polygon_pn[i+1] == 3 )
            {cout << ",";}
        }

    }
    if (checker==false) {cout << "none";}


}

double distance(float x1 , float y1 , float x , float y)      //function to calculate distance bettwen 2 points
{
    return sqrt(pow(y1-y,2)+pow(x1-x,2)) ;
}

double slope (float x1 , float y1 , float x , float y )         //function to calculate slope
{
    return ((y1-y)/(x1-x));
}

void List_Rectangles (string input)                              //function to output List_Rectangles
{
    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */

    bool checker = false;  bool checker1 = false ;


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}
    for (int s=1 ; s <= Number_Polygons(input,string_length);s++)
    {
        int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;
        float x[500] , y[500] ;

        if (polygon_pn[s] == 4)
        {

            for (int i =0 ;  i<= polygon_points[s].length() ;i++ ) //getting place of that "(" and  ")" and ","
            {
                if (polygon_points[s][i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
                if (polygon_points[s][i]== ','){counter2=counter2+1;  col[counter2]=i ;}
                if (polygon_points[s][i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
            }

            for (int i = 1 ; i <=polygon_pn[s] ; i++) {

                x[i]=  atof(polygon_points[s].substr(arc[i] + 1, col[colrep] - arc[i] - 1).c_str()) ;
                y[i]= atof(polygon_points[s].substr(col[colrep] + 1, inarc[i] - col[colrep] - 1).c_str());
                colrep +=2 ;
            }


            if(distance(x[1],y[1],x[2],y[2])==distance(x[3],y[3],x[4],y[4])&&distance(x[2],y[2],x[3],y[3])==distance(x[4],y[4],x[1],y[1]))
            {
                if (distance(x[1],y[1],x[3],y[3])==distance(x[2],y[2],x[4],y[4])) {if (checker1 == true){cout <<",";} cout << s; checker1 = true;}
            }

        }

    }
    if (checker==true) {cout << "none";}


}

void List_Trapezoid (string input)                              //function to output list_tapazoid
{
    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */

    bool checker = false;  bool checker1 = false ;


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}
    for (int s=1 ; s <= Number_Polygons(input,string_length);s++)
    {
        int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;
        float x[500] , y[500] ;

        if (polygon_pn[s] == 4)
        {

            for (int i =0 ;  i<= polygon_points[s].length() ;i++ ) //getting place of that "(" and  ")" and ","
            {
                if (polygon_points[s][i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
                if (polygon_points[s][i]== ','){counter2=counter2+1;  col[counter2]=i ;}
                if (polygon_points[s][i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
            }

            for (int i = 1 ; i <=polygon_pn[s] ; i++) {

                x[i]=  atof(polygon_points[s].substr(arc[i] + 1, col[colrep] - arc[i] - 1).c_str()) ;
                y[i]= atof(polygon_points[s].substr(col[colrep] + 1, inarc[i] - col[colrep] - 1).c_str());
                colrep +=2 ;
            }


            if((slope(x[2],y[2],x[1],y[1])==slope(x[3],y[3],x[4],y[4]) || slope(x[3],y[3],x[2],y[2])==slope(x[4],y[4],x[1],y[1])) && distance(x[1],y[1],x[3],y[3])!=distance(x[2],y[2],x[4],y[4]))
            {
                if (checker1 == true){cout <<",";} cout << s; checker1 = true; checker = true ;
            }

        }

    }
    if (checker==false ) {cout << "none";}


}

void Inside_Rectangle (string input , string p_operation)       //function to get polygon inside rectangle
{
    float xmax , xmin , ymax , ymin ;
    xmax = Maximum_X(p_operation,p_operation.length())  ;
    xmin = Minimum_X(p_operation,p_operation.length())  ;
    ymax = Maximum_Y(p_operation,p_operation.length())  ;
    ymin = Minimum_Y(p_operation,p_operation.length())  ;


    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */

    bool checker = false;  bool checker1 = false ;


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}

    for (int s=1 ; s <= Number_Polygons(input,string_length);s++)
    {

        float xmaxc , ymaxc , xminc , yminc ;

        xmaxc = Maximum_X(polygon_points[s],polygon_points[s].length())  ;
        xminc = Minimum_X(polygon_points[s],polygon_points[s].length())  ;
        ymaxc = Maximum_Y(polygon_points[s],polygon_points[s].length())  ;
        yminc = Minimum_Y(polygon_points[s],polygon_points[s].length())  ;

        if (xmaxc <= xmax && ymaxc <=ymax && xminc <=xmin && yminc <= ymin)
        {
            if (checker1 == true ){cout << ",";}cout << s ; checker= true ; checker1 =true ;
        }
    }
    if (checker==false ) {cout << "none";}





}

void Inside_Circle (string input , string p_operation)          //function to get polgon insude circle
{

    float xb , yb , length ;
    xb = atof(p_operation.substr(1,1).c_str()) ;
    yb =atof(p_operation.substr(3,1).c_str()) ;
    length= atof(p_operation.substr(6,p_operation.length()-6).c_str()) ;


    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */

    bool checker = false;  bool checker1 = false ;


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}

    for (int s=1 ; s <= Number_Polygons(input,string_length);s++)
    {
        int coun=0 ;
        int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;
        float x[500] , y[500] ;


        for (int i =0 ;  i<= polygon_points[s].length() ;i++ ) //getting place of that "(" and  ")" and ","
        {
            if (polygon_points[s][i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
            if (polygon_points[s][i]== ','){counter2=counter2+1;  col[counter2]=i ;}
            if (polygon_points[s][i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
        }
        for (int i = 1 ; i <=polygon_pn[s] ; i++) {

            x[i]=  atof(polygon_points[s].substr(arc[i] + 1, col[colrep] - arc[i] - 1).c_str()) ;
            y[i]= atof(polygon_points[s].substr(col[colrep] + 1, inarc[i] - col[colrep] - 1).c_str());

            if ( distance(x[i],y[i],xb,yb) <= length ) {coun +=1;}
            colrep +=2 ;
        }
        if (coun == polygon_pn[s]){if (checker == true ){cout <<",";} cout <<s ; checker1 = true ; checker =true;}
    }
    if (checker1== false) {cout <<"none";}

}

double Polygon_Area (string points , int number ) //function to points of polygon without redundant
{

    int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;

    for (int i =0 ;  i<= points.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (points[i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
        if (points[i]== ','){counter2=counter2+1;  col[counter2]=i ;}
        if (points[i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
    }
    float x[1000]; float y [1000]; float slope[1000];

    for (int i = 1 ; i <=number ; i++){

        x[i]=atof(points.substr(arc[i]+1,col[colrep]-arc[i]-1).c_str()) ;
        y[i]=atof(points.substr(col[colrep]+1,inarc[i]-col[colrep]-1).c_str())  ;

        colrep +=2 ;

    }

    float xr[1000]; float yr[1000];
    xr[1]=x[1]; yr[1]=y[1];
    int repeater = 2 ;
    int re =0 ; int re2=0 ;
    slope[1]=((y[1+1]-y[1])/(x[1+1]-x[1]));

    for (int i = 2 ; i<=number ; i++)
    {
        slope[i]=((y[i+1]-y[i])/(x[i+1]-x[i]));

        for (int p =2 ; p <=number ;p++){

            if (x[i-1]==x[i] && y[i-1]==y[i]) { re +=1 ; break; } // get redundant of dip point
            if(x[i+1]-x[i] !=0 && slope[i]==slope[i-1]) { re +=1 ;break; } // getting redundant point of slope
            if (x[i+1]-x[i]==0 && y[i+1]-y[i]!=0 && x[i]-x[i-1]==0 && y[i]-y[i-1]!=0 ){  re+=1;   ; break; }// get redundant of x-x =0

            xr[repeater] = x[i];
            yr[repeater] =y[i];

            repeater +=1 ;

            break ;
        }}

    double area = ((xr[repeater-1]*yr[1])-(yr[repeater-1]*xr[1]));
    for (int i=1 ;i<repeater-1 ; i++)
    {
        area +=((xr[i]*yr[i+1])-(yr[i]*xr[i+1])) ;
    }
    return abs(area/2) ;

}

void Polygons_Area_Range (string input , string p_operation)
{
    int semi= p_operation.find(',');
    float minarea = atof(p_operation.substr(0,semi).c_str());
    float maxarea =atof(p_operation.substr(semi+1,p_operation.length()-semi).c_str());

    string points ="" ;
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}


    /*--------------------------------------------------------------------*/

    bool checker1 = false ; bool checker = false ;
    for (int i=1 ; i <= Number_Polygons(input,input.length()); i++)
    {
        if (Polygon_Area(polygon_points[i],polygon_pn[i])<=minarea|| Polygon_Area(polygon_points[i],polygon_pn[i]) >=maxarea)
        {if (checker1==true ){cout<< ",";} cout << i ; checker1 = true ; checker =true; }
    }

    if (checker ==false ){cout << "none"; }
}

bool check (float p1, float p2, float s1, float s2 , float r1,float r2) // point s lies on line segment 'pr'
{
    if (s1 <= max(p1, r1) && s1 >= min(p1, r1) && s2 <= max(p2, r2) && s2 >= min(p2, r2))
        return true;

    return false;
}

int orientation(float p1 , float p2 , float s1 ,float s2 , float r1 , float r2)
{
    int val = (s2 - p2) * (r1 - s1) -
              (s1 - p1) * (r2 - s2);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(float x1,float y1,float x2,float y2,float x3 ,float y3, float x4,float y4)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(x1 ,y1, x2,y2 , x3 ,y3);
    int o2 = orientation(x1 ,y1, x2,y2 , x4 ,y4);
    int o3 = orientation(x3 ,y3, x4,y4 , x1 ,y1);
    int o4 = orientation(x3 ,y3, x4,y4 , x2 ,y2);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && check(x1,y1,x3,y3,x2,y2)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && check(x1,y2, x4 ,y4, x2,y2)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && check(x3,y3, x1,y1, x4,y4)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && check(x3,y3, x2 ,y2, x4,y4)) return true;

    return false; // Doesn't fall in any of the above cases
}

bool isInside(string input, int n, string p_operation)
{


    int arcc[10]; int colc[10]; int inarcc[10]; int counter11=0;int counter22=0; int counter33 = 0; int colrepc = 1;

    for (int i =0 ;  i<= p_operation.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (p_operation[i]== '('){counter11=counter11+1;  arcc[counter11]=i ;}
        if (p_operation[i]== ','){counter22=counter22+1;  colc[counter22]=i ;}
        if (p_operation[i]== ')'){counter33=counter33+1;inarcc[counter33]=i ;}
    }
    float xc; float yc ;

    for (int i = 1 ; i <=1 ; i++){

        xc=atof(p_operation.substr(arcc[i]+1,colc[colrepc]-arcc[i]-1).c_str()) ;
        yc=atof(p_operation.substr(colc[colrepc]+1,inarcc[i]-colc[colrepc]-1).c_str())  ;

        //  cout  << "the value of xc = "  << xc << " " << "the value of yc " << yc <<endl;
        colrepc +=2 ;
    }



    cout << input << endl ;

    string  points = "" ;

    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}


    /*--------------------------------------------------------------------*/
    float x[500] ; float y[500];
    int arc[1000]; int col[1000];int inarc[1000];int   counter1= 0;int  counter2= 0 ;int counter3 = 0 ;int colrep = 1  ;

    for (int i =0 ;  i<= input.length() ;i++ ) //getting place of that "(" and  ")" and ","
    {
        if (input[i]== '('){counter1=counter1+1;  arc[counter1]=i ;}
        if (input[i]== ','){counter2=counter2+1;  col[counter2]=i ;}
        if (input[i]== ')'){counter3=counter3+1;inarc[counter3]=i ;}
    }


    for (int i = 1 ; i <=n ; i++){

        x[i]=atof(input.substr(arc[i]+1,col[colrep]-arc[i]-1).c_str()) ;
        y[i]=atof(input.substr(col[colrep]+1,inarc[i]-col[colrep]-1).c_str());


        colrep +=2 ;

    }




    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;

    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;

        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(x[i],y[i], x[next], y[next], xc ,yc , infinty ,yc ))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false

            if (orientation(x[i],y[i], xc ,yc , x[next],y[next]) == 0)
                return check(x[i],y[i], xc,yc, x[next],y[next]);

            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}

void Polygons_Enclosing_Point (string input , string p_operation)
{


    input = "Polygons=["+ input + "]";
    string points = "";
    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */

    bool checker = false;  bool checker1 = false ;


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}


    for (int i=1 ; i<= Number_Polygons(input,string_length) ; i++ )
    {
        isInside(polygon_points[i],polygon_pn[i],p_operation) ? cout << " yes "<< endl : cout  << " no " << endl;

    }




}





int main () {
    string input;
    string operation;
    string alloperation;
    string n_operation_number ;
    string p_operation_number ;
    string polygons[1000];
    string points = "" ;
    //  input ="Polygons=[(1,2),(4,2),(1,9);(1,2),(4,2),(4,2),(4,2),(4,8),(1,8);(1,1),(2,1),(4,1),(4,2),(4,3),(1,3),(4,7);(1,1),(2,3),(3,6),(1,8);(1,2),(4,2),(1,9),(5,8)]";
    input ="Polygons=[(1,1),(2,1),(4,1),(4,3),(1,3);(1,2),(4,2),(4,2),(4,8),(1,8);(1,2),(4,2),(4,2),(4,2),(4,8),(1,8);(16,31),(34,31),(41,12),(6,12)]";

    // getline(cin, input);




    int string_length = input.length();

    // Outing points whic contain points
    int semi_place [500];
    string polygon_points[500];
    int s =0 ;

    for (int i=0 ; i <= string_length ; i++ )
    {
        if ( input [i]== ';' || input[i]==']')
        { s=s+1 ; semi_place[s]=i ; }
    }

    int m = 9 ;  semi_place[0] = 9 ; // get only points for one polygon
    for (int t=1 ; t<=s ; t++ )
    {
        polygon_points[t] = input.substr(m+1,semi_place[t]- semi_place[t-1]-1) ;
        points = points + polygon_points[t] ;
        if (t!=s){   points= points + "," ; }
        m=semi_place[t];
    }


/*   --------------------- for get points number for one polygon  ------------------  */


    int polygon_pn[500];  int repeat3 =1 ; //get number of polygon points
    for (int i = 0 ; i<Number_Polygons( input , string_length) ; i++)
    {string polygon_points_number =polygon_points[repeat3] ;
        polygon_pn[i+1] = Total_Number_Points(polygon_points[i+1], polygon_points_number.length()) ; repeat3 +=1 ;}


    /*--------------------------------------------------------------------*/




    /*--------------------- for getting total of redundant point -----------------  */

    int Total_Redundant_Points =0 ;
    for (int i=1 ; i<=Number_Polygons(input , string_length) ;i++)
    { Total_Redundant_Points +=Redundant_points(polygon_points[i],polygon_pn[i]); }

    /*--------------------------------------------------------------------*/



    /*  ----------------  getting points without redundant ----------------------  */

    string polygon_without_red = ""; string points_without_red="" ;

    for (int i=1 ; i<=Number_Polygons(input,string_length);i++) {
        points_without_red = polygon_points[i];
        polygons_w_r(points_without_red, polygon_pn[i]);
        polygon_without_red += points_without_red  ;
        if (i<=Number_Polygons(input,string_length)-1){polygon_without_red +=";";}
    }
    //  cout << polygon_without_red <<endl ;
    /*--------------------------------------------------------------------*/






    string magn = "(1,1)";





    Polygons_Enclosing_Point (polygon_without_red,magn);
























    repeat :

    getline (cin ,alloperation) ;
    int  space = 0;  int n_space  =0 ;
    for (int i=0 ; i <= alloperation.length() ;i++)
    { if(alloperation[i]==' '){n_space +=1; space = i ;}}
    if (n_space==0) {operation=alloperation;}
    if (n_space==1) {operation=alloperation.substr(0 ,alloperation.find(' ')); p_operation_number = alloperation.substr(alloperation.find(' ')+1, alloperation.length());}
    if (n_space==2) {operation=alloperation.substr(0,space); p_operation_number=alloperation.substr(space+1,alloperation.length());}



    if
            (operation=="Number_Polygons" || operation=="number_polygons") { cout << Number_Polygons(input , string_length) <<endl;}
    else if
            ( operation=="Total_Number_Points" || operation=="total_number_points"){cout << Total_Number_Points(input , string_length) << endl;}
    else if
            ( operation=="Minimum_X" || operation=="minimum_x"){cout << Minimum_X(points , Total_Number_Points(input , string_length)) << endl;}
    else if
            ( operation=="Maximum_X" || operation=="maximum_x"){cout << Maximum_X(points , Total_Number_Points(input , string_length)) << endl;}
    else if
            ( operation=="Maximum_Y" || operation=="maximum_y"){cout << Maximum_Y(points , Total_Number_Points(input , string_length)) << endl;}
    else if
            ( operation=="Minimum_Y" || operation=="minimum_y"){cout << Minimum_Y(points , Total_Number_Points(input , string_length)) << endl;}
    else if
            ( operation=="Enclosing_Rectangle" || operation=="enclosing_rectangle"){Enclosing_Rectangle(points , input , string_length); cout << endl; }

    else if
            ( operation=="Total_Redundant_Points" || operation=="total_redundant_points")
    { if (Total_Redundant_Points !=0 ){ cout <<Total_Redundant_Points<< endl; }
        if (Total_Redundant_Points==0){cout <<"none"<<endl;}}


    else if
            ( operation=="Polygon_Points" || operation=="polygon_points"){ int pndw = atof(p_operation_number.c_str()) ; polygon_points_re(polygon_points[pndw],polygon_pn[pndw]);}
    else if
            ( operation=="Point_Polygons" || operation=="Point_Polygons"){ polygon_points_fn(input, p_operation_number);}
    else if
            (operation=="List_Polygons_Points More" || operation=="List_Polygons_Points More"){   List_Polygons_Points_More(polygon_without_red,atof(p_operation_number.c_str()) );}
    else if
            (operation=="List_Polygons_Points Less" || operation=="List_Polygons_Points Less"){   List_Polygons_Points_less(polygon_without_red,atof(p_operation_number.c_str()) );}
    else if
            (operation=="List_Polygons_Points Equal" || operation=="list_polygons_points equal"){ List_Polygons_Points_Equal(polygon_without_red,atof(p_operation_number.c_str()) );}
    else if
            (operation=="List_Points_Polygons More" || operation=="list_points_polygons more"){ List_Points_Polygons_More(polygon_without_red,atof(p_operation_number.c_str()) );}
    else if
            (operation=="List_Points_Polygons Less" || operation=="list_points_polygons less"){ List_Points_Polygons_less(polygon_without_red,atof(p_operation_number.c_str()) );}
    else if
            (operation=="List_Points_Polygons Equal" || operation=="list_points_polygons equal"){ List_Points_Polygons_Equal(polygon_without_red,atof(p_operation_number.c_str()) );}
    else if
            (operation=="Polygon_Perimeter" || operation=="polygon_perimeter"){ int pndw = atof(p_operation_number.c_str()) ;polygon_perimeter(polygon_points[pndw],polygon_pn[pndw]);}
    else if
            (operation=="List_Triangles" || operation=="list_triangles"){ List_Triangles(polygon_without_red);}
    else if
            (operation=="List_Rectangles" || operation=="list_rectangles"){ List_Rectangles(polygon_without_red);}
    else if
            (operation=="List_Trapezoid" || operation=="list_trapezoid"){ List_Trapezoid(polygon_without_red);}
    else if
            (operation=="Inside_Rectangle" || operation=="inside_rectangle"){ Inside_Rectangle(polygon_without_red ,p_operation_number);}
    else if
            (operation=="Inside_Circle" || operation=="Inside_Circle"){ Inside_Circle(polygon_without_red ,p_operation_number);}
    else if
            (operation=="Polygon_Area" || operation=="Polygon_Area"){ int pndw = atof(p_operation_number.c_str()) ; cout << Polygon_Area(polygon_points[pndw],polygon_pn[pndw]) <<endl;}
    else if
            (operation=="Polygons_Area_Range" || operation=="Polygons_Area_Range"){Polygons_Area_Range(input, p_operation_number);}



















    else if (operation == "Quit" || operation == "quit") { return 0; }
    goto repeat ;

}  //main of operation cons
