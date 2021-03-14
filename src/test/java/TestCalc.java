import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.util.regex.Pattern;
import static com.jcabi.matchers.RegexMatchers.matchesPattern;
import static org.junit.Assert.assertThat;

import static org.hamcrest.MatcherAssert.assertThat;

public class TestCalc {

    private ByteArrayOutputStream output = new ByteArrayOutputStream();

    @Before
    public void setUpStreams() {
        System.setOut(new PrintStream(output));
    }

    @After
    public void cleanUpStreams() {
        System.setOut(null);
    }

    @Test
    public void systemForWhichEveryValueIsDecisionShouldReturnFive(){
        double a=0.0,b=0.0,c=0.0,d=0.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("5", output.toString());
        //Assert.assertEquals("5",result);
    }

    @Test
    public void systemWithUniqueDecisionShouldReturnTwoAndDecision(){
        double a=3.0,b=4.0,c=5.0,d=2.0,e=10.0,f=8.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertThat(output.toString(),matchesPattern("^[2]\\s-?\\d+\\.\\d*\\s-?\\d+\\.\\d*"));
        //Assert.assertEquals("2",result);
    }

    @Test
    public void systemWithUniqueYDecisionAndOneNotZeroParameterShouldReturnFourAndY(){
        double a=0.0,b=0.0,c=0.0,d=1.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertThat(output.toString(),matchesPattern("^[4]\\s-?\\d+\\.\\d*"));
        //Assert.assertEquals("4.1",result);
    }

    @Test
    public void systemWithUniqueXDecisionAndOneNotZeroParameterShouldReturnThreeAndDecision(){
        double a=0.0,b=0.0,c=1.0,d=0.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertThat(output.toString(),matchesPattern("^[3]\\s-?\\d+\\.\\d*"));
        //Assert.assertEquals("3.1",result);
    }

    @Test
    public void systemWithNoDecisionsShouldReturnZero(){
        double a=0.0,b=3.0,c=0.0,d=1.0,e=5.0,f=6.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertThat(output.toString(),matchesPattern("0"));
        //Assert.assertEquals("0",result);
    }

    @Test
    public void systemWithUniqueYDecisionShouldReturnFourAndDesicion(){
        double a=0.0,b=1.0,c=0.0,d=1.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertThat(output.toString(),matchesPattern("^[4]\\s-?\\d+\\.\\d*"));
        //Assert.assertEquals("4.2",result);
    }

    @Test
    public void systemWithUniqueXDecisionShouldReturnThreeAndDecision(){
        double a=0.1,b=0.0,c=1.0,d=0.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertThat(output.toString(),matchesPattern("^[3]\\s-?\\d+\\.\\d*"));
        //Assert.assertEquals("3.2",result);
    }

    @Test
    public void systemWithInfiniteAmountOfDecisionsShouldReturnOneAndIndexes(){
        double a=1.0,b=0.0,c=1.0,d=1.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertThat(output.toString(),matchesPattern("^[1]\\s-?\\d+\\.\\d*\\s-?\\d+\\.\\d*"));
        //Assert.assertEquals("3.3",result);
    }

    @Test
    public void systemWithInfiniteAmountOfDecisions1ShouldReturnOneAndIndexes(){
        double a=1.0,b=1.0,c=1.0,d=0.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertThat(output.toString(),matchesPattern("^[1]\\s-?\\d+\\.\\d*\\s-?\\d+\\.\\d*"));
        //Assert.assertEquals("1.1",result);
    }

    @Test
    public void systemWithInfiniteAmountOfDecisions2ShouldReturnOneAndIndexes(){
        double a=0.0,b=3.0,c=32.0,d=1.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertThat(output.toString(),matchesPattern("^[1]\\s-?\\d+\\.\\d*\\s-?\\d+\\.\\d*"));
        //Assert.assertEquals("1.2",result);
    }

    @Test
    public void systemWithInfiniteAmountOfDecisions3ShouldReturnOneAndIndexes(){
        double a=54.0,b=54.0,c=0.0,d=3.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertThat(output.toString(),matchesPattern("^[1]\\s-?\\d+\\.\\d*\\s-?\\d+\\.\\d*"));
        //Assert.assertEquals("1.3",result);
    }

    @Test
    public void systemWithInfiniteAmountOfDecisions4ShouldReturnOneAndIndexes(){
        double a=54.0,b=54.0,c=5.0,d=5.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertThat(output.toString(),matchesPattern("^[1]\\s-?\\d+\\.\\d*\\s-?\\d+\\.\\d*"));
        //Assert.assertEquals("1.4",result);
    }

    @Test
    public void systemWithoutSpecialStuffShouldReturnNinetyNine(){
        double a=54.0,b=54.0,c=5.0,d=4.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals(output.toString(),"Are u kidding me?");
        //Assert.assertEquals("99",result);
    }

}
