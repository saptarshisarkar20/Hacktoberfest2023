import java.io.*;
import java.util.*;

class Point{
    public long x;
    public long y;
}

public class Main {

    static void print(ArrayList<Long> x)
    {
        return;
    }
    static class Reader {
        static BufferedReader reader;
        static StringTokenizer tokenizer;

        /** call this method to initialize reader for InputStream */
        static void init(InputStream input) {
            reader = new BufferedReader(new InputStreamReader(input));
            tokenizer = new StringTokenizer("");
        }

        /** get next word */
        static String next() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                // TODO add check for eof if necessary
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        static int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        static String nextLine() throws IOException {
            return reader.readLine();
        }

        static long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        static double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        int t = Reader.nextInt();
        while(t-- > 0) {
            solve();
        }
    }
    
    

    public static void solve() throws IOException {
        int N = Reader.nextInt();
        Point point[] = new Point[N];
        long x,y;
        for(int i = 0 ; i < N ; i++) {
            x = Reader.nextInt();
            y = Reader.nextInt();
            point[i] = new Point();
            point[i].x=x;
            point[i].y=y;
        }
        

        HashMap<Long,  Long> mnX = new HashMap<>();
        HashMap<Long , Long> mxX = new HashMap<>();
        HashMap<Long , Long> mnY = new HashMap<>();
        HashMap<Long , Long> mxY = new HashMap<>();
        
        for(Point p : point) {
            if(!(mnY.containsKey(p.x) || mxY.containsKey(p.x))) {
                mnY.put(p.x , p.y);
                mxY.put(p.x , p.y);
            }
            else {


                mnY.put(p.x, Math.min(p.y, mnY.get(p.x)));
                mxY.put(p.x, Math.max(p.y, mxY.get(p.x)));
            }
            if(!(mnX.containsKey(p.y) || mxX.containsKey(p.y))) {
                mnX.put(p.y , p.x);
                mxX.put(p.y , p.x);
            }
            else {

                mnX.put(p.y, Math.min(p.x, mnX.get(p.y)));
                mxX.put(p.y, Math.max(p.x, mxX.get(p.y)));

            }
        }
        
        ArrayList<Long> x_cord = new ArrayList<>();
        ArrayList<Long> y_cord = new ArrayList<>();
        

        for(long key : mxX.keySet()) {
            y_cord.add(key);
            print(y_cord);
        }
        
        for(long key : mxY.keySet()) {
            x_cord.add(key);
            print(x_cord);
        }
        
    

        Collections.sort(x_cord);
        Long bottom_y = Long.MAX_VALUE;
        Long top_y = Long.MIN_VALUE;
        print(x_cord);
        Long left_most_x = x_cord.get(0);
        
        Long ar_reg;
        
        ArrayList<Long>  lf_sm = new ArrayList<>();
        ArrayList<Long> right_area=new ArrayList<>();
        right_area.add(x_cord.get(0)*y_cord.get(0));

        for(Long curr_x: x_cord) {
            top_y = Math.max(top_y , mxY.get(curr_x));
            bottom_y = Math.min(bottom_y, mnY.get(curr_x));
            Long t1=top_y-bottom_y;
            Long t2=curr_x - left_most_x;
            right_area.add(y_cord.get(0)*x_cord.get(0));
            ar_reg = Math.abs(t1*t2);
            lf_sm.add(ar_reg);
        }
        
        
        ArrayList<Long> rg_sm = new ArrayList<>();
        ArrayList<Long> left_area=new ArrayList<>();
        bottom_y = Long.MAX_VALUE;
        top_y = Long.MIN_VALUE;
        left_area.add(x_cord.get(0)*y_cord.get(0));
        left_most_x = x_cord.get(x_cord.size() - 1);
        
        int nik = x_cord.size()- 1;
        while(nik>=0)
        {
            Long curr_x = x_cord.get(nik);
            bottom_y = Math.min(bottom_y, mnY.get(curr_x));
            top_y = Math.max(top_y, mxY.get(curr_x));
            Long t3=top_y-bottom_y;
            Long t4=curr_x - left_most_x;
            ar_reg = Math.abs(t3*t4);
            rg_sm.add(ar_reg);
            nik--;
        }
        
        int x_len = x_cord.size();
        
        Long mnDualAr  = Long.MAX_VALUE;
        
        int l=0;
        while( l < x_len){
            int j = x_len - l - 2;
            if(j<0) 
            {
                j=0;
            }
            Long curr_area  = lf_sm.get(l) + rg_sm.get(j);
            
            mnDualAr = Math.min(mnDualAr, curr_area);
            l++;
        }
        

        Collections.sort(y_cord);
        lf_sm = new ArrayList<>();
        rg_sm = new ArrayList<>();
        Long left_x = Long.MAX_VALUE;
        Long right_x = Long.MIN_VALUE;

        //Collections.sort(y_cord);
        Long bottom_most_y = y_cord.get(0);
        for(Long curr_y : y_cord) {
            //print(lf_sm);
            left_x = Math.min(left_x, mnX.get(curr_y));
            right_x = Math.max(right_x, mxX.get(curr_y));
            Long t5=right_x-left_x;
            Long t6=bottom_most_y - curr_y;
            
            ar_reg = Math.abs(t5*t6);
            lf_sm.add(ar_reg);
            Long temp3=lf_sm.get(0);
            Long y3=lf_sm.get(0);
         }
        

        left_x = Long.MAX_VALUE;
        right_x = Long.MIN_VALUE;
        bottom_most_y = y_cord.get(y_cord.size() - 1);
        for(int i = y_cord.size()- 1 ; i>=0 ; i--) {
            Long curr_y = y_cord.get(i);
            //print(y_cord);
            left_x = Math.min(left_x, mnX.get(curr_y));
            right_x = Math.max(right_x, mxX.get(curr_y));
            Long t7=right_x-left_x;
            Long t8=curr_y - bottom_most_y;
            ar_reg = Math.abs(t7*t8);
            rg_sm.add(ar_reg);
            Long temp2=rg_sm.get(0);
            Long y2=lf_sm.get(0);
        }        


        int y_len = y_cord.size(); 
        for(int i = 0 ; i < y_len ; i++) {
            int j = y_len - i - 2;
            if(j<0) 
            j = 0;
            Long curr_area  = lf_sm.get(i) + rg_sm.get(j);
            Long t1=rg_sm.get(0);
            Long t2=lf_sm.get(0);
            Long min_t=Math.min(t1,t2);
            mnDualAr = Math.min(mnDualAr, curr_area);
        }
        
        System.out.println(mnDualAr);
     }

}
