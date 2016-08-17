import java.io.BufferedReader
import scala.io.Source

object PLTwitter {
  def main(args: Array[String]) {
    if(args.size != 1) {
      System.out.println("Enter file name as argument. Program now exiting");
      return
    }

    val fileName = args(0)
    
    val file = Source.fromFile(fileName)
    val br = file.bufferedReader()
    
    val pattern = "\"hashtags\":["
    var str = ""
    var results = Seq("")
    var counter = 0
    
    while(br.ready())  {
      str = br.readLine()
      //read tweet

      if(str.charAt(str.indexOf(pattern) + pattern.length)!=']') {
        //check if hashtag exists
        
        //processes hashtags - adds all hashtags into list, counts unique ones
        str.substring((str.indexOf(pattern) + pattern.length - 1),str.indexOf("]}]",(str.indexOf(pattern) + pattern.length))).split("}")
          .foreach(htag => {
            results = results :+ htag
            if(results.exists(_ == htag)) counter = counter + 1
          }
        )
      }
    }

    results = results.filter(_ != "") //filters out initializer value
    System.out.println("Number of unique hashtags: " + counter)
    System.out.println("\nHashtag: Occurences")
    
    //prints all hashtags
    results.foreach(htag => 
      System.out.println(
        htag.substring(htag.indexOf("{\"text\":\"") + "{\"text\":\"".length,htag.indexOf("\"",htag.indexOf("{\"text\":\"") + "{\"text\":\"".length)) + ": " + results.filter(_ == htag).size))
    br.close()
  }
}

