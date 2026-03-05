type DatabaseLocal = {
  connectionString: string;
  connect(): void;
  isOpen: boolean;
};

type DatabaseDeployed = {
  dbName: string;
  port: number;
  secrit: string;
  connect(): void;
  isOpen: boolean;
};

type unifiedLink = DatabaseDeployed & DatabaseLocal;

let connection: unifiedLink;

// we can do the same with interfaces

interface TOne {
  one: string;
  two: string;
}

interface TTwo {
  three: number;
  four: number;
}

interface Intersectioni extends TOne, TTwo {}

let botato: Intersectioni;
