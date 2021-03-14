import org.junit.Assert;
import org.junit.Test;

public class TestCalc {

    @Test
    public void systemForWhichEveryValueIsDecisionShouldReturnFive(){
        double a=0.0,b=0.0,c=0.0,d=0.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("5",result);
    }

    @Test
    public void systemWithUniqueDecisionShouldReturnTwo(){
        double a=3.0,b=4.0,c=5.0,d=2.0,e=10.0,f=8.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("2",result);
    }

    @Test
    public void systemWithUniqueYDecisionAndOneNotZeroParameterShouldReturnFourPointOne(){
        double a=0.0,b=0.0,c=0.0,d=1.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("4.1",result);
    }

    @Test
    public void systemWithUniqueXDecisionAndOneNotZeroParameterShouldReturnThreePointOne(){
        double a=0.0,b=0.0,c=1.0,d=0.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("3.1",result);
    }

    @Test
    public void systemWithNoDecisionsShouldReturnZero(){
        double a=0.0,b=3.0,c=0.0,d=1.0,e=5.0,f=6.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("0",result);
    }

    @Test
    public void systemWithUniqueYDecisionShouldReturnFourPointTwo(){
        double a=0.0,b=1.0,c=0.0,d=1.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("4.2",result);
    }

    @Test
    public void systemWithUniqueXDecisionShouldReturnThreePointTwo(){
        double a=0.1,b=0.0,c=1.0,d=0.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("3.2",result);
    }

    @Test
    public void systemWithUniqueXDecision2ShouldReturnThreePointThree(){
        double a=1.0,b=0.0,c=1.0,d=1.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("3.3",result);
    }

    @Test
    public void systemWithInfiniteAmountOfDecisionsShouldReturnOnePointOne(){
        double a=1.0,b=1.0,c=1.0,d=0.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("1.1",result);
    }

    @Test
    public void systemWithInfiniteAmountOfDecisionsShouldReturnOnePointTwo(){
        double a=0.0,b=3.0,c=32.0,d=1.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("1.2",result);
    }

    @Test
    public void systemWithInfiniteAmountOfDecisionsShouldReturnOnePointThree(){
        double a=54.0,b=54.0,c=0.0,d=3.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("1.3",result);
    }

    @Test
    public void systemWithInfiniteAmountOfDecisionsShouldReturnOnePointFour(){
        double a=54.0,b=54.0,c=5.0,d=5.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("1.4",result);
    }

    @Test
    public void systemWithoutSpecialStuffShouldReturnNinetyNine(){
        double a=54.0,b=54.0,c=5.0,d=4.0,e=0.0,f=0.0;

        String result = Calc.calculate(a,b,c,d,e,f);
        Assert.assertEquals("99",result);
    }

}
