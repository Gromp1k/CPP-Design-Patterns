#include<iostream>
#include<memory>
#include<vector>

//GetDetails()
class IVehicle {
	public:
	    IVehicle() = default;
		virtual ~IVehicle(){std::cout<<"~IVehicle()\n\n";}
		virtual void GetDetails() =0;
	protected:
	    std::string PATH = "IVehicle";
};

//OnNitroActivated()
class Sportscar : virtual public IVehicle {
	public:
		Sportscar() : IVehicle() {PATH += "/Sportscar";};
		~Sportscar(){ std::cout << "~Sportscar()/";};
		virtual void OnNitroActived()=0;
		
};

class SC_Opel : public Sportscar {
	public:
		SC_Opel(): Sportscar(){ PATH += "/SC_Opel"; }
		~SC_Opel() { std::cout << "~SC_Opel()/"; };
		void OnNitroActived() override{ std::cout << "SC_Opel::OnNitroActived()\n";};
		void GetDetails() override{
		    std::cout << PATH << '\n';
		    OnNitroActived();
		};
};

class SC_Scania : public Sportscar {
	public:
		SC_Scania() : Sportscar() {PATH += "/SC_Scania"; 	};
		~SC_Scania(){std::cout << "~SC_Scania/";};
		void OnNitroActived() override{ std::cout << "SC_Scania::OnNitroActived()\n";};
		void GetDetails() override{
		    std::cout << PATH << "\n";
		    OnNitroActived();
		};
};

//OnHatchOpen()
class DeliveryVan : virtual public IVehicle {
	public:
		DeliveryVan() : IVehicle(){PATH += "/DeliveryVan";}
		~DeliveryVan(){std::cout << "~DeliveryVan()/";};
		virtual void OnHatchOpen()=0;
		
};

class DV_Opel : public DeliveryVan {
	public:
		DV_Opel(){PATH += "/DV_Opel";}
		~DV_Opel(){std::cout << "~DV_Opel()/";};
		void OnHatchOpen() override{ std::cout << "DV_Opel::OnHatchOpen()\n";};
		void GetDetails() override{
		    std::cout << PATH << '\n';
		    OnHatchOpen();
		};
};

class DV_Scania : public DeliveryVan {
	public:
		DV_Scania(){ PATH+="/DV_Scania";}
		~DV_Scania(){std::cout << "~DV_Scania()/";};
		void OnHatchOpen() override{ std::cout << " DV_Scania::OnHatchOpen()\n";};
		void GetDetails() override{
		    std::cout << PATH << '\n';
		    OnHatchOpen();
		};
};

class IVehicleFactory{
    public:
        virtual std::shared_ptr<Sportscar> CreateSportscar() const =0;
        virtual std::shared_ptr<DeliveryVan> CreateDeliveryVan() const =0;
};

class OpelFactory : public IVehicleFactory{
	public:
	OpelFactory(){ }
	~OpelFactory(){ }
    std::shared_ptr<Sportscar> CreateSportscar()const override{ return std::make_shared<SC_Opel>(); }
    std::shared_ptr<DeliveryVan> CreateDeliveryVan()const override{ return std::make_shared<DV_Opel>(); }
   
};

class ScaniaFactory : public IVehicleFactory{
	public:
	ScaniaFactory(){ }
	~ScaniaFactory(){ }
    std::shared_ptr<Sportscar> CreateSportscar()const override{ return std::make_shared<SC_Scania>(); }
    std::shared_ptr<DeliveryVan> CreateDeliveryVan()const override{ return std::make_shared<DV_Scania>(); }
    
};

int main(int c, char** v){

    std::vector< std::shared_ptr<IVehicleFactory> > factories {
        {std::make_shared<ScaniaFactory>()},
        {std::make_shared<OpelFactory>()}
    };
    
    for(const auto& factory : factories){
        factory->CreateDeliveryVan()->GetDetails();
        factory->CreateSportscar()->GetDetails();
    } 
    
    
}