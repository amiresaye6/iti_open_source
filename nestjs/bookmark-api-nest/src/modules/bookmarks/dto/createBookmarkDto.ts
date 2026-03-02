export interface CreateBookmarkDto {
  url: string;
  title: string;
  description?: string;
  tags?: string[];
}
