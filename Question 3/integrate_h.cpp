#include<cmath>
#include<iostream>

void gauss_quadrature(int n, double x[], double w[]);

void normal_vec(double first[], double second[], double norm[])//function to find outward unit norms
{
    double z_0,z_1;
    z_0=second[1]-first[1];
    z_1=first[0]-second[0];
    norm[0]=z_0/sqrt(pow(z_0,2)+pow(z_1,2));
    norm[1]=z_1/sqrt(pow(z_0,2)+pow(z_1,2));
}
void parameter_map(double first[], double second[], double mid[], double scale[])//function to find appropriate parameter mapping
{
    mid[0]=(first[0]+second[0])/2;
    mid[1]=(first[1]+second[1])/2;//midpoints
    scale[0]=(-first[0]+second[0])/2;
    scale[1]=(-first[1]+second[1])/2;//scaling in each direction divided by 2
}
double dot(double first[], double second[])//dot product function
{
    return ((first[0]*second[0])+(first[1]*second[1]));
}

//return integral of f(x,y)=(x^5)*(y^3) over a given irregular polygon. Using gauss quadrature
double integrate_h(int n)
{
    int n_edges=6;//6 edges
    double int_approx=0, *first_coord, *second_coord, *norm, *mid, *scale, *x, *w;//variables
    double x_vectors[]={0.1,0.7,1,0.75,0.5,0,0.1};//x coords, repeating first at end for last edge
    double y_vectors[]={0,0.2,0.5,0.85,1,0.25,0};//y coords
    x=new double [n];//arrays
    w=new double [n];
    norm=new double[2];
    mid=new double[2];
    scale=new double[2];
    for(int i=1;i<=n_edges;i++)
    {
        first_coord = new double[2];//creates coords for first vector in edge
        first_coord[0]=x_vectors[i-1];
        first_coord[1]=y_vectors[i-1];

        second_coord = new double[2];//creates coords for second vector in edge
        second_coord[0]=x_vectors[i];
        second_coord[1]=y_vectors[i];

        normal_vec(first_coord, second_coord, norm);//finds norm
        parameter_map(first_coord, second_coord, mid, scale);//finds parameter mapping

        gauss_quadrature(n,x,w);//finds quadrature points and weights
        for(int j=1;j<=n;j++)
        {
            double x_i[]={(x[j-1]*scale[0])+mid[0], (x[j-1]*scale[1])+mid[1]};//applies parameter mapping to quadrature points
            int_approx=int_approx+(sqrt(pow(scale[0],2)+pow(scale[1],2))*dot(x_i,norm)*pow(x_i[0],5)*pow(x_i[1],3)*w[j-1]);
        }                   //sums( Jacobian                    *         x_i dot norm *         function        * weights

    }
    delete [] x;// deletes arrays
    delete [] w;
    delete [] norm;
    delete [] mid;
    delete [] scale;
    delete [] first_coord;
    delete [] second_coord;
    return (int_approx)/10;// divide by (q+2=10)
}

