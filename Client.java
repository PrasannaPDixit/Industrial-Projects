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
        Create a object of Socket class and establish connection with client
        Use PrintStream class to sending messages to server
        Use Bufferedreader of reading the messages from user as well as server
        Use a special word for terminating the connection    
    End
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////

public class Client
{
    public static void main(String ar[])
    {

        try
        {
            String str1,str2;

            System.out.println("Client application is running");

            Socket s = new Socket("localhost",2200);

            PrintStream ps = new PrintStream(s.getOutputStream());

            BufferedReader br1 = new BufferedReader(new InputStreamReader(s.getInputStream()));

            BufferedReader br2 = new BufferedReader(new InputStreamReader(System.in));

            do
            {
                System.out.print("Client :=>\t");
                str2 = br2.readLine();
                ps.println(str2);
                
                str1 = br1.readLine();
                System.out.println("Server :=>\t"+str1);
            }while(str1 != null);
        }
        catch(Exception obj)
        {
            System.out.println("Exception Occcured : "+obj);
        }  

    }
}
      
