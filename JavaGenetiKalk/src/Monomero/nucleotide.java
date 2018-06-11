package Monomero;   

public class nucleotide extends Monomero{
    private boolean _hasOxy;
    private String _comp;

    public nucleotide(String n, String s, double p, boolean hasOxy, String comp){
        super(n, s, p);
        _hasOxy=hasOxy;
        _comp=comp;
    }

    public String getComp(){
        return _comp;
    }

    public boolean getHasOxy(){
        return _hasOxy;
    }

    public void setComp(String comp){
        _comp=comp;
    }

    public void setHasOxy(boolean hasOxy){
        _hasOxy=hasOxy;
    }

}
