
namespace Variant1{
   //  Исключения
    public class PassengersOverload :  Exception{}
    public class TruckOverload :  Exception{}

    public abstract class Car {
      
		public double Velocity{get;set;}
		public double MaxFuelVolume{get; set;}
		public double FuelVolume{get;set;}
		public double FuelConsumption{get;set;} // mean(volume / length)
		public string Name{get;set;}
		public abstract double LostRemainginDistance{get;}
	}

	public class PassengerCar : Car{
		private int _MaxPassengers;
		
		public PassengerCar(int maxPassenger){
			_MaxPassengers = maxPassenger;
		}
		private int _Passengers;
		public int Passengers{
			get => _Passengers ;
			set{
				if(value > _MaxPassengers)
					throw new PassengersOverload();
				_Passengers = value;
			}
		}
		public int MaxPassengers => _MaxPassengers;
		public override double LostRemainginDistance => (1e0 - .06 * _Passengers);
	}

	public class Truck : Car{
		private double _MaxLoad; // kg
		public Truck (double maxLoad){
			_MaxLoad = maxLoad;
		}
		public double MaxLoad => _MaxLoad;
        public double _Load;
		public double Load{
			get => _Load;
			set{
				if(value > _MaxLoad)
					throw new TruckOverload();
				_Load = value;
			}
		}
		public override double LostRemainginDistance => (1e0 - .04/ 200e0 ); // over meter

	}


	public struct MeasureResult{
		public string Message;
		public double Value;
	}

	public static class Measure{

		public static MeasureResult RequiredTime(this Car car, double distance){
			var requiredFuel = distance * car.FuelConsumption; 
			if(( requiredFuel - car.FuelVolume) > 0)
			{
				return new MeasureResult{Message="NotEnoughFuel", Value=0e0} ;
			}
			return new MeasureResult{Message = "", Value=distance * car.Velocity * car.LostRemainginDistance};
		}

		public static MeasureResult RemainingDistanceOfFuel(this Car car, double fuel){
			string msg = null;
			if(fuel > car.MaxFuelVolume)
				msg = "FuelOverload";
			return new MeasureResult{Message=msg, Value = fuel / car.FuelConsumption * car.LostRemainginDistance};
		}

		public static MeasureResult RemainingDistanceCurrent(this Car car)
		{
            return new MeasureResult{Message="", Value=car.FuelVolume / car.FuelConsumption * car.LostRemainginDistance};
		}
	}
}
