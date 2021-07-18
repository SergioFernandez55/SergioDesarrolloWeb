import { Component, OnInit } from '@angular/core';
import { NotesService } from 'src/app/services/notes.service';
import { Note } from 'src/app/types/models';

@Component({
  selector: 'app-list',
  templateUrl: './list.page.html',
  styleUrls: ['./list.page.scss'],
})
export class ListPage implements OnInit {
  notes: Note[] = [];

  constructor(private noteService: NotesService) {}

  ngOnInit() {
    //Sacamos las notas del servicio de notas
    this.notes = this.noteService.notes;
    console.log(this.notes);
  }

}
