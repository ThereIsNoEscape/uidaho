// Jonathan Buch, CS 210 HW#6, Java Assignment

import java.io.*;
import java.lang.reflect.Array;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;
import java.lang.String;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class uml2uni {
    public static void main(String[]args) {
        tokenizer tokens = new tokenizer();

        String infile;
        if (args.length > 0) {
            infile = args[0];
            tokens.read(Paths.get(infile));
        }
        else {
            tokens.read(Paths.get("test.uml"));
        }

        Path output = Paths.get("uml2uni.icn");
        tokens.output(output);
    }
}

class tokenizer {
    // Hashtable to store the classes
    Hashtable classH = new Hashtable();

    // Classes - Hash Table
    public Hashtable makeclass(String classname) {
        Hashtable classblock = new Hashtable();
        classH.put(classname, classblock);
        classblock.put("methodlist", new Hashtable());
        classblock.put("args", new ArrayList());
        classH.put(classname, classblock);
        return classblock;
    }

    // Reading a File
    public void read(Path filename) {
        File file = new File(filename.toUri());
        FileInputStream fis;
        try {
            fis = new FileInputStream(file);
            byte[] data = new byte[(int) file.length()];
            fis.read(data);
            fis.close();
            String str = new String(data, "UTF-8");
            parse(str);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Writing to a File
    public void writeF(String line, Path filename) {
        Charset charset = Charset.forName("US-ASCII");
        try (BufferedWriter writer = Files.newBufferedWriter(filename, charset)) {
            writer.write(line, 0, line.length());
        } catch (IOException x) {
            System.err.format("IOException: %s%n", x);
        }
    }

    public void output(Path filename) {
        String file = "";
        Enumeration itr =  classH.keys();
        while (itr.hasMoreElements()) {
            String className = (String) itr.nextElement();
            Hashtable classBlock = (Hashtable) classH.get(className);
            file += String.format("class %s()\n", className);
            Hashtable methodBlock = (Hashtable) classBlock.get("methodlist");
            Enumeration methoditr = methodBlock.keys();
            while (methoditr.hasMoreElements()) {
                String methodName = (String) methoditr.nextElement();
                file += String.format("    %s ()\n", methodName);
            }
            file += String.format("end\n\n");
        }
        System.out.print(file);
        writeF(file, filename);
    }

    public void parse(String file) {
        Pattern classPattern = Pattern.compile("class\\s*([\"\\s\\w]*?)\\s*\\{([^\\{]*)\\}", Pattern.DOTALL | Pattern.MULTILINE);
        Matcher classMatcher = classPattern.matcher(file);

        while( classMatcher.find() ) {
            String className = classMatcher.group(1);
            String classContents = classMatcher.group(2);

            Hashtable classBlock = makeclass(className.replace("\"", "").replace(" ", "_").trim());
            Hashtable methods = (Hashtable) classBlock.get("methodlist");

            Pattern methodPattern = Pattern.compile("[-+]* *([\\w]*)\\((.*)\\)");
            Matcher methodMatcher = methodPattern.matcher(classContents);

            while( methodMatcher.find() ) {
                String methodName = methodMatcher.group(1).trim();
                String methodArgs = methodMatcher.group(2).trim();
                methods.put(methodName, methodArgs);
            }

        }
    }

}
