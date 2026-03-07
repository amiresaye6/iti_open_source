import { Component } from '@angular/core';
import { Istudent } from '../istudent';

@Component({
  selector: 'app-student',
  standalone: false,
  templateUrl: './student.html',
  styleUrl: './student.css',
})
export class Student {
  students: Istudent[] = [];
  constructor() {
    this.students = [
      {
        name: 'Amir Alsayed',
        id: 123456,
        age: 23,
        photoUrl: './images.jfif',
      },
      {
        name: 'Botato Chipso',
        id: 564226,
        age: 55,
        photoUrl: 'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQPHLThNbz89WvCrB-YCLz7_2HrxW-wcG5jzA&s',
      },
      {
        name: '7amood Mody',
        id: 7897845,
        age: 12,
        photoUrl: 'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQ2ZdbcrnnuQqa5xKpWEFt7okX4mD_hSEcTSA&s',
      },
    ];
  }
}
