package day2;

import java.util.StringTokenizer;

public class IpCutter {

    String cmdLine;

    public IpCutter(String ip) {
        cmdLine = ip;
    }

    String[] splitCut() {
        return this.cmdLine.split("\\.");
    }

    String[] streingTokenizerCut() {
        StringTokenizer st = new StringTokenizer(this.cmdLine, ".");
        
        String[] res = new String[st.countTokens()];
        
        int i = 0;
        while (st.hasMoreTokens()) {
            res[i] = st.nextToken();
            i++;
        }
        return res;
    }
}