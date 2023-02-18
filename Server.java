import java.net.*;
import java.io.*;

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Steps to follow while programming
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Step1    Understand the problem statement
// Step2    Write an algorithm
// Step3    Decide the programming language 
// Step4    Write the program
// step5    Test the program

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Project Name : File packer unpacker using command user interface
//Author :       Prasanna Prabhakarrao Dixit
//Date :         06/02/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Algorithm
//////////////////////////////////////////////////////////////////////////////////////////////////////

/*
    START
        Create a object of ServerSocket class to start the server
        Create Object of Socket class to accept re connection request from client
        Use PrintStream class to sending messages to client
        Use Bufferedreader of reading the messages from user as well as client
        Use a special word for terminating the connection    
    End
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
public class Server
{
    public static void main(String ar[])
    {
        try
        {
            String str1,str2,str3,str4;

            System.out.println("Server application is running");

            ServerSocket ss = new ServerSocket(2200);

            System.out.println("Server is running at port number 2100 at waiting for client");

            Socket s = ss.accept();

            System.out.println("Request of client gets accepted!");

            PrintStream ps = new PrintStream(s.getOutputStream());

            BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));

            BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

            File fobj = new File("ChatHistory.txt");
            fobj.createNewFile();

            FileOutputStream FOSobj = new FileOutputStream(fobj);

            byte Buffer1[] = new byte[1014];
            byte Buffer2[] = new byte[1024];

            while(!((str1 = br1.readLine()).equals("End")))
            {
                System.out.println("Client :=>\t"+str1);
                System.out.print("Server :=>\t");
                str2 = br2.readLine();
                ps.println(str2);

                str3 = "\nClient :=>\t"+str1;
                str4 = "\nServer :=>\t"+str2;

                Buffer1 = str3.getBytes();
                Buffer2 = str4.getBytes();

                FOSobj.write(Buffer1,0,Buffer1.length);
                FOSobj.write(Buffer2,0,Buffer2.length);
            }
        }
        catch(Exception obj)
        {
            System.out.println("Exception Occcured : "+obj);
        } 

    }
}
         
