// Jonathan Buch, CS 210 HW#6, Java Assignment

import java.io.*;
import java.nio.*;
import java.util.*;
import java.lang.String;

class uml2uni {
        public static void main(String[]args) {
                tokenizer tokens = new tokenizer();
                tokenizer.read(Paths.get("test.uml"));
                Path output = Paths.get("uml2uni.icn");
                tokenizer.outputFile(output);
        }
}

class tokenizer {
// Hashtable to store the classes
        Hashtable classH = new Hashtable();

// Classes - Hash Table
        public Hashtable makeclass(String classname) {
                Hashtable classblock = new Hashtable();
                classH.put(classname, classblock);
                classblock.put("methods", new Hashtable());
                classblock.put("args", new ArrayList());
                return classblock;
        }

// Reading a File
        public void read(Path filename) {
                Charset charset = Charset.forName("US-ASCII");
                try (BufferedReader reader = Files.newBufferedReader(filename, charset)) {
                        String line = null;
                        while((line = reader.readLine()) != null) {
                                System.out.println(line);
                        }
                } catch (IOException x) {
                        System.err.format("IOException: %s%n", x);
                }
        }

// Writing to a File
        pubilc void writeF(String line, Path filename) {
                Charset charset = Charset.forName("US-ASCII");
                try (BufferedWriter writer = Files.newBufferedWriter(filename, charset)) {
                        writer.write(line, 0, line.length());
                } catch (IOException x) {
                System.err.format("IOException: %s%n", x);
        }

// Create Unicon Code
        public void outputFile(Path filename) {
                Iterator<String> class = classH.keys();
                while(class.hasNext()) {
                        String classname = class.next();
                        Hashtable classblock = (Hashtable) class.get(classname);
                        writef(String.format("class %s(%s)%n", classname, concat(", ", (List<String>) classblock.get("arguments"))), file);
                        Hashtable methodsList = (Hashtable) classblock.get("Cmethods");
                        Iterator<String> methods = methodlist.keys();
                        while(methods.next()) {
                                String methodname = (String) methods.next();
                                List<String> methodargs = (List<String>) methodlist.get(methodname);
                                writef(String.printf("   method %s(%s)%n   end%n"
                                        methodname, concat(", ", methodargs)), filename);
                        }
                        writef("end\n", filename);
                }
        }

// Arguments - Strings
        public List<String> tokenargs(String args) {
                List<String> arglist = new ArrayList<>();
                String[] newargs = args.split(",");
                return arglist;

// Regular Expressions - Hashtable
        Hashtable regexH = new Hashtable();


// Tokenizer
        public tokenizer() {
                regexH.put("class", Pattern.compile("class "[a-zA-Z0-9_]+));
                regexH.put("Cargs", Pattern.compile([a-zA-Z0-9_]+" : "+[a-zA-Z0-9_]+);
                regexH.put("Cmethods", Pattern.compile("class "[a-zA-Z0-9_]+));

// Line Tokenizer
        public void linetokens(String line) {
                String regex, classname, methodname, arg, args;
                Iterator regexlist = regexh.keys();
                while(regexlist.hasNext()) {
                        regex = (String) regexlist.next();
                        pattern = re


// Concatination of a list
        public String concat(String delimiter, List<String> strings) {
                Iterator<String> combine = strings.iterator();
                StringBuilder newstring = new StringBuilder();
                while(combine.hasNext()) {
                        newstring.append(combine.next()).append(combine.hasNext() ? delimiter : "");
                }
                return newstring.toString();
        }
}
