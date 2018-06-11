
package Monomero;

public class Monomero{
    private String _name;
    private String _acr;
    private double _mass;

    public Monomero(String name, String acr, double mass){
        _name=name;
        _acr=acr;
        _mass=mass;
    }

    public String getName(){
        return _name;
    }

    public void setName(String name) {
        _name=name;
    }

    public String getAcr(){
        return _acr;
    }

    public void setAcr(String acr) {
        _acr=acr;
    }

    public double getMass(){
        return _mass;
    }

    public void setMass(double mass){
        _mass=mass;
    }
}
