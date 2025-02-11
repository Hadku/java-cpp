package message;


import java.util.ArrayList;
import java.util.Date;
import account.Account;

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
        if (repliedTo != null) 
        {
            repliedTo.addReply(this);
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
