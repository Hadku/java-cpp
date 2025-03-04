package message;


import java.util.ArrayList;
import java.util.Date;
import account.Account;
import java.io.*;


public class Message
{
    private Account from;
    
    private Date date;
    
    private Message repliedTo;
    
    private ArrayList<Message> replies;

    private String body;

    public Message(Account from, Message repliedTo, String body)
    {
        this.from = from;
        this.repliedTo = repliedTo;
        this.body = body;
        this.replies = new ArrayList<>();
        this.date = new Date();
        if (repliedTo != null) 
        {
            repliedTo.addReply(this);
        }
    }

    public Message(BufferedReader br, Message repliedTo) 
        throws IOException
    {
        //////////////////////////
        this.from = new Account(br); 
        this.date = new Date(Long.parseLong(br.readLine())); 
        this.body = br.readLine();
        this.replies = new ArrayList<>();
        this.repliedTo = repliedTo;
        if (repliedTo != null) 
        {
            repliedTo.addReply(this);
        }

        int numReplies = Integer.parseInt(br.readLine());
        for (int i = 0; i < numReplies; i++) 
        {
            String className = br.readLine();
            Message reply;
            if (className.equals("message.Post")) 
            {
                reply = new Post(br, this);
            } 
            else 
            {
                reply = new DirectMessage(br, this);
            }
            replies.add(reply);
        }

    }

    public void save(BufferedWriter bw) 
        throws IOException
    {
        /////////////////
        bw.write(from.toString());
        bw.newLine();
        bw.write(Long.toString(date.getTime())); // Save date as timestamp
        bw.newLine();
        bw.write(body);
        bw.newLine();
        bw.write(Integer.toString(replies.size()));
        bw.newLine();
        for (Message reply : replies) 
        {
            bw.write(reply.getClass().getName());
            bw.newLine();
            reply.save(bw);
        }

    }

    public Message getRepliedTo()
    {
        return repliedTo;
    }
    
    public Message getReply(int index)
    {
        if (index < 0 || index >= replies.size()) 
        {
            return null;
        }
        return replies.get(index);
    }

    @Override
    public String toString()
    {
        StringBuilder sb = new StringBuilder();

        sb.append("Date: ").append(date).append("\n");
        sb.append("From: ").append(from).append("\n");



        if (repliedTo != null) 
        {
            sb.append("In reply to: ").append(repliedTo.from).append("\n");
        }
        else 
        {
            sb.append("\nThis message is not a reply to any other message.\n");
        }


        if (!replies.isEmpty()) 
        {
            sb.append("Replies: ");

            for (int i = 0; i < replies.size(); i++) 
            {
                sb.append(replies.get(i).from.toString());
                if (i < replies.size() - 1) 
                {
                    sb.append(", ");
                }
            }

            sb.append("\n");
        }

        sb.append("\n").append(body);

        //return repliedTo.toString();
        return sb.toString();

    }

    private void addReply(Message message)
    {
        replies.add(message);
    }
}
