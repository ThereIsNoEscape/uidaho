for(k = 1; k < 1000000; k = k + 1){
	term = (4*(pow(-1, k + 1)/(2.0*k-1)));
	sum = sum + term;
	cout << k << " " << 4*sum << endl;
term = calc(k);
	double calc(int x){
	double answer;
	answer = (4*(pow(-1, x+1)/(2.0*x-1)));
	return answer;
double fun(double); // prototype or declaration

int main(){
	double x,y;
	y = 7;
	x = fun(y);
	cout << x << endl;
}

double fun(double z){
	double answer;
	answer = z*z*z;
	return answer;
}
