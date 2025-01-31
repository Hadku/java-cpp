public class Message
{
    //-from : Account
    //-date : Date
    //-repliedTo : Message
    //-replies : Message[] <<ArrayList>>

    //+Message(from : Account, repliedTo : Message, body : String)
    //+getRepliedTo() : Message
    //+getReply(index : int) : Message
    //+toString() : String <<overide>>
    //-addReply(message : Message)
}