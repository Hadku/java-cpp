package message;

import account.Account;
import java.io.*;


public class DirectMessage extends Message
{
    private Account to;

    public DirectMessage(Account from, Account to, Message repliedTo, String body)
    {
        super(from, repliedTo, body);
        this.to = to;
    }

    public DirectMessage(BufferedReader br, Message repliedTo) 
        throws IOException
    {
        super(br, repliedTo);
        this.to = new Account(br);

    }

    public void save(BufferedWriter bw) 
        throws IOException
    {
        super.save(bw);
        bw.write(to.toString());
        bw.newLine();

        
    }

    @Override
    public String toString()
    {
        return "To: " + to + "\n" + super.toString();
    }
}