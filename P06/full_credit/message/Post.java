package message;

import account.Account;
import java.io.*;


public class Post extends Message
{
    public Post(Account from, Group group, Message repliedTo, String body)
    {
        super(from, repliedTo, body);
        this.group = group;
    }

    public Post(BufferedReader br, Message repliedTo) 
        throws IOException
    {
        super(br, repliedTo);
        this.group = new Group(br);

    }

    public void save(BufferedWriter bw) 
        throws IOException
    {
        super.save(bw);
        bw.write(group.toString());
        bw.newLine();

    }

    @Override
    public String toString()
    {
        return "\nGroup: " + group + "\n" + super.toString();
    }

    private Group group;
    
}