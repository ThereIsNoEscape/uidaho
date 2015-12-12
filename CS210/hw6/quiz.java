import java.io.*;

class copier{
	public static void main(String[]args){
		String s;
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		while((s = in.readLine()) != null)
			System.out.printf("%s%n\n", s);
	}
}
